code = files('module.c')

lib = static_library('fscl-c',
    code,
    include_directories: dir)

fscl_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
