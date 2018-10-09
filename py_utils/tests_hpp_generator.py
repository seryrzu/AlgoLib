def tests_hpp_generator(tests_filenames, outfile, namespace, test_dir='tests'):
    N = len(tests_filenames)
    tests_filenames = ', '.join(f'"{filename}"' for filename in tests_filenames)
    code = f"""#include <array>
#include <string_view>

namespace {namespace} {{

constexpr std::array<std::string_view, {N}> tests_filenames {{ {tests_filenames} }};

}} // End namespace {namespace}
"""
    with open(outfile, 'w') as f:
        print(code, file=f)
