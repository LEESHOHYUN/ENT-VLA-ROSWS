from setuptools import find_packages
from setuptools import setup

setup(
    name='ur_robot_manager_interfaces',
    version='0.1.0',
    packages=find_packages(
        include=('ur_robot_manager_interfaces', 'ur_robot_manager_interfaces.*')),
)
