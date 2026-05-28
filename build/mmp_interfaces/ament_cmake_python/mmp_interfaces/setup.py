from setuptools import find_packages
from setuptools import setup

setup(
    name='mmp_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('mmp_interfaces', 'mmp_interfaces.*')),
)
