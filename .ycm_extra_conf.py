def FlagsForFile( filename, **kwargs ):
  return {
    'flags': [ '-x', 'c++', '-Wall', '-Wextra', '-Werror', '-std=c++98',
    '-I/home/borealis/work/etl-98/include/', '-I/home/borealis/work/etl-98/libs/cpputest/include/'],
  }

