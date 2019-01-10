project (
    'Ex9AllTogether',
    'cpp',
    version: '1.0',
    meson_version: '>=0,46',
    default_options: ['cpp_std=c++11']
)
subdir('src')

doxyfile = configuration_data()
doxyfile.set('OUTPUT_DIRECTORY', meson.build_root())
configure_file(input: 'Doxyfile.in', output: 'Doxyfile', 
    configuration: doxyfile)
doxygen = find_program('doxygen')
run_target('doc', command: [doxygen,
    join_paths(meson.build_root(), 'Doxyfile')])
