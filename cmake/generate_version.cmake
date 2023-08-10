# This file is part of Desktop App Toolkit,
# a set of libraries for developing nice desktop applications.
#
# For license and copyright information please follow this link:
# https://github.com/desktop-app/legal/blob/master/LEGAL

function(generate_version target_name)
    find_package(Python REQUIRED)

    set(gen_dst ${CMAKE_CURRENT_BINARY_DIR}/gen)
    file(MAKE_DIRECTORY ${gen_dst})

    set(gen_timestamp ${gen_dst}/version.timestamp)
    set(gen_files
        ${gen_dst}/ANGLEShaderProgramVersion.h
    )
    
    set(gen_response ${gen_dst}/version_response.file)
    get_target_property(sources_list ${target_name} SOURCES)
    file(WRITE ${gen_response} "")
    foreach(source ${sources_list})
        file(APPEND ${gen_response} "${source}\n")
    endforeach()

    add_custom_command(
    OUTPUT
        ${gen_timestamp}
    BYPRODUCTS
        ${gen_files}
    COMMAND
        ${Python_EXECUTABLE}
        ${angle_loc}/program_serialize_data_version.py
        ${gen_files}
        ${gen_response}
    COMMAND
        echo 1> ${gen_timestamp}
    COMMENT "Generating ANGLEShaderProgramVersion.h (${target_name})"
    DEPENDS
        ${angle_loc}/program_serialize_data_version.py
    )
    generate_target(${target_name} version ${gen_timestamp} "${gen_files}" ${gen_dst})
endfunction()
