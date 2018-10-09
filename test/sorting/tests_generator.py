import os
import random
import argparse
import sys

THIS_DIR = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(THIS_DIR,
                             os.path.pardir,
                             os.path.pardir,
                             'py_utils'))
from os_utils import smart_makedirs
from tests_hpp_generator import tests_hpp_generator


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-o", "--outdir",
                        help="output directory", default='tests')
    parser.add_argument("-N", help="Number of tests",
                        default=50, type=int)
    parser.add_argument("--min-elem", help="Min element",
                        default=-10000, type=int)
    parser.add_argument("--max-elem", help="Min element",
                        default=+10000, type=int)
    parser.add_argument("--min-size", help="Min sample size",
                        default=1000, type=int)
    parser.add_argument("--max-size", help="Min sample size",
                        cdefault=100000, type=int)
    parser.add_argument("--seed", help="Seed for simulations",
                        default=random.randint(0, 1000000), type=int)
    params = parser.parse_args()

    random.seed(params.seed)
    params.outdir = os.path.join(THIS_DIR, params.outdir)
    # TODO if dir exists, check its consistency with current tests_fn.hpp. If
    # consistent stop. If not —-- report an error.
    smart_makedirs(params.outdir)

    filenames = []
    for i in range(params.N):
        sample_len = random.randint(params.min_size, params.max_size)
        sample = [str(random.randint(params.min_elem, params.max_elem))
                  for j in range(sample_len)]
        filename = 'sortingtest_%d_seed_%d_samplesize_%d.txt' % \
                   (i, params.seed, sample_len)
        filename = os.path.abspath(os.path.join(params.outdir, filename))
        filenames.append(filename)

        with open(filename, 'w') as f:
            print(' '.join(sample), file=f)

    tests_hpp_generator(filenames, os.path.join(THIS_DIR, 'tests_fn.hpp'),
                        'algolib::sorting')


if __name__ == "__main__":
    main()
