#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped
import serial

# Replace with the actual serial port your Arduino is connected to
ARDUINO_PORT = "/dev/ttyACM0"
BAUD_RATE = 9600

class SlamControlNode:
    def __init__(self):
        rospy.init_node('slam_control_node')
        self.serial_conn = serial.Serial(ARDUINO_PORT, BAUD_RATE, timeout=1)
        rospy.Subscriber('/slam_out_pose', PoseStamped, self.pose_callback)
        rospy.loginfo("SLAM control node started.")
        self.last_sent = None

    def pose_callback(self, msg):
        x = msg.pose.position.x
        y = msg.pose.position.y
        theta = msg.pose.orientation.z  # Simplified for 2D

        rospy.loginfo(f"Pose: x={x:.2f}, y={y:.2f}, theta={theta:.2f}")

        # Movement logic: go forward if within bounds, else stop
        if abs(x) < 2.0 and abs(y) < 2.0:
            command = 'F'  # Forward
        else:
            command = 'S'  # Stop

        if command != self.last_sent:
            self.serial_conn.write(command.encode())
            self.last_sent = command
            rospy.loginfo(f"Sent command: {command}")

    def run(self):
        rospy.spin()

if __name__ == '__main__':
    try:
        node = SlamControlNode()
        node.run()
    except rospy.ROSInterruptException:
        pass
