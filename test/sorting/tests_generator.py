import os
import random
import argparse
import sys


sys.path.append(os.path.join(os.path.pardir, os.path.pardir, 'py_utils'))
from os_utils import smart_makedirs
from tests_hpp_generator import tests_hpp_generator


def smart_makedirs(dirname):
    import errno

    try:
        os.makedirs(dirname)
    except OSError as exc:
        if exc.errno != errno.EEXIST:
            raise exc


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-o", "--outdir", help="output directory", default='tests')
    parser.add_argument("-N", help="Number of tests", default=100, type=int)
    parser.add_argument("--min-elem", help="Min element", default=-10000, type=int)
    parser.add_argument("--max-elem", help="Min element", default=+10000, type=int)
    parser.add_argument("--min-size", help="Min sample size", default=1000, type=int)
    parser.add_argument("--max-size", help="Min sample size", default=1000000, type=int)
    parser.add_argument("--seed", help="Seed for simulations", default=random.randint(0, 1000000), type=int)
    params = parser.parse_args()

    random.seed(params.seed)
    smart_makedirs(params.outdir)


    filenames = []
    for i in range(params.N):
        print(i + 1, params.N)
        sample_len = random.randint(params.min_size, params.max_size)
        sample = [str(random.randint(params.min_elem, params.max_elem)) for j in range(sample_len)]
        filename = 'sortingtest_%d_seed_%d_samplesize_%d.txt' % (i, params.seed, sample_len)
        filenames.append(filename)

        with open(os.path.join(params.outdir, filename), 'w') as f:
            print(' '.join(sample), file=f)

    tests_hpp_generator(filenames, 'tests_fn.hpp', 'algolib::sorting')



if __name__ == "__main__":
    main()
