# Single tracked object from SAM2S (instrument or hand)
string object_id          # e.g. "myringotomy_knife", "surgeon_hand_left"
string object_class       # instrument type or "hand"
float32[4] bbox           # [x_min, y_min, x_max, y_max] normalized 0-1
float32 confidence        # detection confidence
bool visible              # currently visible in frame
geometry_msgs/Point position  # 3D position estimate (if depth available)
