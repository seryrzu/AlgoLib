import sys
import json


class SoftwareRequirementError(Exception):
    def __init__(self, software, req_version, run_version):
        self.software = software
        self.req_version = req_version
        self.run_version = run_version

    def __str__(self):
        return "Requirement for %s is not satisfied. Required version: %s. " \
            "Running version: %s" % \
            (self.software, self.req_version, self.run_version)


def successful_check(software, req_version, run_version):
    print("Sucessful check: %s. Required version %s. Running version: %s" %
          (software, req_version, run_version))
    return


def check_python(req_version):
    run_version = sys.version_info[:2]
    run_version_major, run_version_minor = run_version
    run_version_str = '.'.join(str(x) for x in run_version)

    req_version_major, req_version_minor = \
        [int(x) for x in req_version.split('.')]

    if run_version_major > req_version_major or \
            run_version_major == req_version_major and \
            run_version_minor >= req_version_minor:
        successful_check('python', req_version, run_version_str)
        return

    raise SoftwareRequirementError('python', req_version, run_version_str)


def main():
    print('===== Check of software requirements')

    requirements_filename = 'requirements.json'
    with open(requirements_filename, 'r') as f:
        requirements = json.load(f)

    check_python(requirements['python'])
    print('====== Successful check of requirements. '
          'CMake and C++ compliler versions are checked later')


if __name__ == '__main__':
    main()
