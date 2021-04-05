file(REMOVE_RECURSE
  "test_parser"
  "test_parser.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/test_parser.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
