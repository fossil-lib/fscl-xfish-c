code = files('nlp.c', 'anomaly.c', 'jellyfish.c')

lib = static_library('fscl-xfish-c',
    code,
    include_directories: dir)

fscl_xfish_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
