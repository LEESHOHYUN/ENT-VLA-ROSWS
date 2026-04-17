# Safety Gate output
std_msgs/Header header
uint8 decision

# Decision codes
uint8 GO=0
uint8 HOLD=1
uint8 ABORT=2

string reason             # human-readable reason for HOLD/ABORT
