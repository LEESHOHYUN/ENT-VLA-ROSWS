from setuptools import find_packages, setup

package_name = 'nurse_perception'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='hrlsh',
    maintainer_email='whysojjjjj@gmail.com',
    description='Perception nodes: SAM2S object tracking, Emergency Classifier',
    license='MIT',
    entry_points={
        'console_scripts': [
            # 'sam2s_node = nurse_perception.sam2s_node:main',
            # 'emergency_node = nurse_perception.emergency_node:main',
        ],
    },
)
