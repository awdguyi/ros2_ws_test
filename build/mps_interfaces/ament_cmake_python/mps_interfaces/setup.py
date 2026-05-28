from setuptools import find_packages
from setuptools import setup

setup(
    name='mps_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('mps_interfaces', 'mps_interfaces.*')),
)
