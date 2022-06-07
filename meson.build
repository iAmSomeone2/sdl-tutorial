project('SDL Tutorial', 'cpp',
  version: '0.1.0',
  default_options: [
    'warning_level=3',
    'cpp_std=c++17'])

conf_data = configuration_data()

conf_data.set('project_name', meson.project_name())

configure_file(input: 'src/projconfig.h.in',
  output: 'projconfig.h',
  configuration: conf_data)

config_include = include_directories('.')

fmt_dep = dependency('fmt', version: '>=8.1',
  required: true,
  static: false)

sdl2_dep = dependency('sdl2', 'SDL2', version: '>=2.0',
  required: true,
  static: false)

app_srcs = files('src/main.cpp', 'src/Game.cpp', 'src/SDLException.cpp')

exe = executable('sdl-tutorial', app_srcs,
  dependencies: [
    fmt_dep,
    sdl2_dep
  ],
  include_directories: config_include,
  install: true)

test('basic', exe)
