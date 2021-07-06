# This file is part of Desktop App Toolkit,
# a set of libraries for developing nice desktop applications.
#
# For license and copyright information please follow this link:
# https://github.com/desktop-app/legal/blob/master/LEGAL

function(generate_commit_id target_name)
    find_package(Python REQUIRED)

    set(gen_dst ${CMAKE_CURRENT_BINARY_DIR}/gen)
    file(MAKE_DIRECTORY ${gen_dst})

    set(gen_timestamp ${gen_dst}/commit_id.timestamp)
    set(gen_files
        ${gen_dst}/angle_commit.h
    )
    add_custom_command(
    OUTPUT
        ${gen_timestamp}
    BYPRODUCTS
        ${gen_files}
    COMMAND
        ${Python_EXECUTABLE}
        ${angle_loc}/commit_id.py
        gen ${gen_files}
    COMMAND
        echo 1> ${gen_timestamp}
    COMMENT "Generating angle_commit.h (${target_name})"
    DEPENDS
        ${angle_loc}/commit_id.py
    )
    generate_target(${target_name} commit_id ${gen_timestamp} "${gen_files}" ${gen_dst})
endfunction()
