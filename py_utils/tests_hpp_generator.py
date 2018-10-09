def tests_hpp_generator(tests_fns, outfile, namespace, test_dir='tests'):
    N = len(tests_fns)
    tests_fns = ', '.join(f'"{fn}"' for fn in tests_fns)
    code = f"""#include <array>
#include <string_view>

namespace {namespace} {{

constexpr std::array<std::string_view, {N}> tests_fns {{ {tests_fns} }};

}} // End namespace {namespace}
"""
    with open(outfile, 'w') as f:
        print(code, file=f)
