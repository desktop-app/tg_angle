# ZLib
set(TG_ANGLE_ZLIB_INCLUDE_PATH "" CACHE STRING "Include path for zlib.")
function(link_zlib target_name)
    if (TG_ANGLE_PACKAGED_BUILD)
        find_package(ZLIB REQUIRED)
        target_link_libraries(${target_name} PRIVATE ZLIB::ZLIB)
    else()
        if (TG_ANGLE_ZLIB_INCLUDE_PATH STREQUAL "")
            message(FATAL_ERROR "You should specify 'TG_ANGLE_ZLIB_INCLUDE_PATH'.")
        endif()

        target_include_directories(${target_name}
        PRIVATE
            ${TG_ANGLE_ZLIB_INCLUDE_PATH}
        )
        if (WIN32)
            target_compile_definitions(${target_name}
            PRIVATE
                ZLIB_WINAPI
            )
        endif()
    endif()
endfunction()
