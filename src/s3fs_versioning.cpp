/*
 * s3fs - FUSE-based file system backed by Amazon S3
 *
 * Copyright(C) 2007 Takeshi Nakatani <ggtakec.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <string>
#include <cstring>
#include "s3fs_versioning.h"
#include "string_util.h"

bool is_versioning_context(const char *path) {
    return is_prefix(path, VERSIONS_DIRNAME.c_str());
}

// The bucket content is the same in all versions, so remove the versions prefixes
const char *remove_versions_prefix(const char *path) {
    if (VERSIONS_DIRNAME == path) {
        return "/";
    }
    
    if (is_prefix(path, VERSIONS_DIRNAME.c_str())) {
        return path + VERSIONS_DIRNAME.length();
    }

    return path;
}
