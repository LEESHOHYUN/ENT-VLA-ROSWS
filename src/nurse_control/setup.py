from setuptools import find_packages, setup

package_name = 'nurse_control'

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
    description='Control nodes: VLA Executor, UR5e handover controller',
    license='MIT',
    entry_points={
        'console_scripts': [
            # 'vla_executor_node = nurse_control.vla_executor_node:main',
            # 'handover_controller_node = nurse_control.handover_controller_node:main',
        ],
    },
)
