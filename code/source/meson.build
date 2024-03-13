cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

code = files('jellyfish.c', 'anomaly.c', 'nlu.c', 'ner.c', 'nlg.c', 'nlp.c')

lib = static_library('fscl-xfish-c',
    code,
    dependencies: m_dep,
    include_directories: dir)

fscl_xfish_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
