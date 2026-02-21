/*
 *  Copyright 2017 The Android Open Source Project
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef ANDROID_SYNC_H
#define ANDROID_SYNC_H

#include <stdint.h>
#include <sys/cdefs.h>
#include <poll.h>
#include <time.h>
#include <errno.h>

__BEGIN_DECLS

/**
 * Wait on a fence file descriptor.
 *
 * This function blocks until the fence is signaled or an error occurs.
 * It is equivalent to the deprecated libsync function sync_wait().
 *
 * @param fd      The fence file descriptor.
 * @param timeout Timeout in milliseconds, or -1 to wait indefinitely.
 * @return 0 on success, or a negative error code on failure:
 *         -ETIME if the wait timed out,
 *         -EINVAL if the fd is invalid,
 *         -errno for other errors.
 */
static inline int sync_wait(int fd, int timeout) {
    struct pollfd fds = { .fd = fd, .events = POLLIN, .revents = 0 };
    struct timespec ts;
    struct timespec *pts = NULL;

    if (timeout >= 0) {
        ts.tv_sec = timeout / 1000;
        ts.tv_nsec = (timeout % 1000) * 1000000L;
        pts = &ts;
    }

    int ret = ppoll(&fds, 1, pts, NULL);
    if (ret < 0) {
        return -errno;
    } else if (ret == 0) {
        return -ETIME;
    }
    if (fds.revents & (POLLERR | POLLNVAL)) {
        return -EINVAL;
    }
    return 0;
}

__END_DECLS

#endif /* ANDROID_SYNC_H */