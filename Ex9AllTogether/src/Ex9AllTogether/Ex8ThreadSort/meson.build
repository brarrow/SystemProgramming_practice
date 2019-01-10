Ex8ThreadSort_src = files([
    'main.cc'
])

threads = dependency('threads')

executable(
    'Ex8ThreadSort',
    include_directories: src,
    sources: Ex8ThreadSort_src,
    dependencies: [threads],
    install: true
)