import os
import random
import argparse


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


    for i in range(params.N):
        print(i + 1, params.N)
        sample_len = random.randint(params.min_size, params.max_size)
        sample = [str(random.randint(params.min_elem, params.max_elem)) for j in range(sample_len)]
        filename = 'sortingtest_%d_seed_%d_samplesize_%d.txt' % (i, params.seed, sample_len)

        with open(os.path.join(params.outdir, filename), 'w') as f:
            print(' '.join(sample), file=f)



if __name__ == "__main__":
    main()
