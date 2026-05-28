from setuptools import find_packages
from setuptools import setup

setup(
    name='zmr_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('zmr_interfaces', 'zmr_interfaces.*')),
)
