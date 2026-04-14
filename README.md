🌿 Nature & Village Illustration – Computer Graphics Project

📌 Overview

This project is a 2D animated village scene developed using OpenGL (C language). It presents a natural environment with hills, river, houses, trees, bamboo fences, boats, and clouds.

The scene is dynamic and interactive, featuring real-time animation and day/night switching, making it both visually appealing and educational.

✨ Features

🌄 Complete village environment (hills, river, houses, trees)
🚤 Moving boats (animation using translation)
☁️ Moving clouds
🌞🌙 Day & Night mode (keyboard control)
🌟 Stars visible in night mode
🏠 Light effects in houses during night

🎮 Controls

Key	Action
D	Switch to Day Mode
N	Switch to Night Mode

🧠 Algorithms Used

DDA (Digital Differential Analyzer) Algorithm Used for drawing bamboo fence lines
Midpoint Circle Algorithm Used for drawing sun (day) and moon (night)

🔄 Transformations Used
2D Translation For moving boats and clouds
2D Scaling For resizing objects (e.g., small boat)

🛠️ Technologies Used

C++ Programming Language
OpenGL
GLUT

🖥️ How to Run
Install OpenGL & GLUT on your system

Compile the code:

g++ your_file.cpp -lGL -lGLU -lglut

Run the program:

./a.out
📸 Output Preview

<img width="961" height="566" alt="image" src="https://github.com/user-attachments/assets/da982964-17bb-47e9-b13d-7e0d475780a5" />
<img width="971" height="567" alt="image" src="https://github.com/user-attachments/assets/98bd73c3-34b6-4b94-bae8-c52f3af0f208" />



🎯 Project Objectives

Create a realistic 2D village scene
Implement classical graphics algorithms
Demonstrate animation using transformations
Provide user interaction

🚧 Limitations

Only 2D (no 3D graphics)
Limited interaction
No textures or advanced lighting

🚀 Future Improvements

Add weather effects (rain, fog)
Implement 3D version
Add more user controls
Include sound effects

👨‍💻 Author
Md. Ashiqur Rahman
Department of CSE
Daffodil International University

📚 References

Computer Graphics with OpenGL – Hearn & Baker
OpenGL Documentation
Research on DDA & Midpoint Algorithms
