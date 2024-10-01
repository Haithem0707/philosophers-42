<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body style="font-family: Arial, sans-serif; background-color: #f0f4f8; color: #333; line-height: 1.6; margin: 0; padding: 0;">
    <header style="background: #35424a; color: #ffffff; padding: 30px 0; text-align: center; margin-bottom: 30px; box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);">
        <h1 style="margin: 0; font-size: 36px; font-weight: 400;">Philo Project Documentation 📜</h1>
        <p>Comprehensive guide for the Philo project by Haithem Bendjaballah</p>
    </header>
    <nav style="background: #35424a; color: #ffffff; padding: 10px 0; text-align: center; position: sticky; top: 0; z-index: 1000; box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);">
        <a href="#overview" style="color: #ffffff; padding: 10px 20px; text-decoration: none; font-weight: 500;">📖 Project Overview</a>
        <a href="#mandatory" style="color: #ffffff; padding: 10px 20px; text-decoration: none; font-weight: 500;">🛠️ Mandatory Part</a>
        <a href="#bonus" style="color: #ffffff; padding: 10px 20px; text-decoration: none; font-weight: 500;">🚀 Bonus Part</a>
        <a href="#structure" style="color: #ffffff; padding: 10px 20px; text-decoration: none; font-weight: 500;">📂 Directory Structure</a>
        <a href="#learning-points" style="color: #ffffff; padding: 10px 20px; text-decoration: none; font-weight: 500;">📚 Key Learning Points</a>
    </nav>
    <div style="width: 80%; margin: auto; padding: 20px; overflow: hidden;">
        <!-- Project Overview -->
        <div id="overview" style="background: #ffffff; padding: 20px 30px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); margin-bottom: 30px;">
            <h2 style="border-bottom: 2px solid #e8491d; padding-bottom: 10px; margin-bottom: 20px; font-size: 24px; font-weight: bold;">📖 Project Overview</h2>
            <p>The `philo` project is a well-known concurrency problem inspired by the classic "Dining Philosophers" problem 🍽️. The project is designed to test your understanding of multi-threading, process synchronization, and resource management in concurrent environments. By working through this project, students will gain deeper insights into managing shared resources, preventing deadlocks, and ensuring data consistency when dealing with multiple threads or processes 🔄.</p>
            <p>Throughout the project, you’ll encounter challenges related to mutex locks, semaphores, and shared memory handling, which are critical concepts in systems programming 💻.</p>
        </div>
        <!-- Mandatory Part -->
        <div id="mandatory" style="background: #ffffff; padding: 20px 30px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); margin-bottom: 30px;">
            <h2 style="border-bottom: 2px solid #e8491d; padding-bottom: 10px; margin-bottom: 20px; font-size: 24px; font-weight: bold;">🛠️ Mandatory Part</h2>
            <p><strong>Goal:</strong> The mandatory part focuses on implementing the Dining Philosophers problem using multi-threading 🧵. Each philosopher is represented as a thread, and forks are shared resources protected by mutexes 🔒 to avoid race conditions ⚠️.</p>
            <p>This part emphasizes the proper use of thread synchronization mechanisms and managing concurrent access to shared resources. You will need to ensure that no philosopher starves 🚫, that deadlocks are avoided ❌, and that each philosopher alternates between eating 🍽️, thinking 💭, and sleeping 💤 without interference.</p>
            <div style="background: #f4f4f4; padding: 15px; margin: 20px 0; border-left: 4px solid #35424a; overflow-x: auto; border-radius: 4px; box-shadow: 0 1px 3px rgba(0, 0, 0, 0.1);">
                <pre>
Key requirements include:
- Implementing the behavior of each philosopher as a separate thread.
- Ensuring that no two adjacent philosophers pick up the same fork simultaneously.
- Avoiding deadlock situations by managing the order of lock acquisition.
                </pre>
            </div>
        </div>
        <!-- bonus Part -->
        <div id="bonus" style="background: #ffffff; padding: 20px 30px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); margin-bottom: 30px;">
            <h2 style="border-bottom: 2px solid #e8491d; padding-bottom: 10px; margin-bottom: 20px; font-size: 24px; font-weight: bold;">🚀 Bonus Part</h2>
            <p><strong>Goal:</strong> The bonus part extends the project by requiring a multi-process implementation 🚦. Each philosopher is represented as an independent process, with forks and other resources shared using semaphores 📊.</p>
            <p>In this part, you’ll need to manage inter-process communication and ensure that all processes synchronize correctly, as processes do not share the same memory space 🧠. This implementation is more complex and requires careful handling of process creation, termination, and cleanup 🧹.</p>
            <div style="background: #f4f4f4; padding: 15px; margin: 20px 0; border-left: 4px solid #35424a; overflow-x: auto; border-radius: 4px; box-shadow: 0 1px 3px rgba(0, 0, 0, 0.1);">
                <pre>
Key considerations:
- Using semaphores to control access to shared resources.
- Implementing logic to detect when a philosopher has finished eating and terminate processes accordingly.
- Ensuring proper process cleanup to prevent orphan or zombie processes.
                </pre>
            </div>
        </div>
        <!-- Directory Structure -->
        <div id="structure" style="background: #ffffff; padding: 20px 30px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); margin-bottom: 30px;">
            <h2 style="border-bottom: 2px solid #e8491d; padding-bottom: 10px; margin-bottom: 20px; font-size: 24px; font-weight: bold;">📂 Directory Structure</h2>
            <p>The directory structure for the `philo` project is as follows. This organization helps maintain a clean and understandable layout, making it easier for students to navigate the project and find relevant files.</p>
            <pre style="white-space: pre; background: #f4f4f4; padding: 20px; border-radius: 8px; box-shadow: 0 1px 3px rgba(0, 0, 0, 0.1); margin-bottom: 30px;">
├── philo
│   ├── Makefile 📝
│   ├── error_management.c ❗
│   ├── init_control.c 🛠️
│   ├── philo_eating.c 🍽️
│   ├── philo_eating_helper.c 🥄
│   ├── philo_header.h 📂
│   ├── philo_int_main.c 🏁
│   ├── philos_routine.c 🔄
│   ├── project_manager.c 🗂️
│   ├── thread_creation.c 🧵
│   ├── utils.c 🔧
│   └── utils2.c 🔧
├── philo_bonus
│   ├── Makefile 📝
│   ├── error_management.c ❗
│   ├── init_control.c 🛠️
│   ├── philo_header.h 📂
│   ├── philo_int_main.c 🏁
│   ├── philos_routine.c 🔄
│   ├── program_clean_up.c 🧹
│   └── utils.c 🔧
            </pre>
            <p>Each file serves a specific purpose:</p>
            <ul>
                <li><strong>Makefile:</strong> Used for building the project and managing dependencies.</li>
                <li><strong>error_management.c:</strong> Contains functions for error handling and reporting.</li>
                <li><strong>init_control.c:</strong> Responsible for initializing control variables and structures.</li>
                <li><strong>philo_eating.c:</strong> Implements the eating behavior of philosophers.</li>
                <li><strong>philo_header.h:</strong> Contains header declarations and constants used across the project.</li>
                <li><strong>philos_routine.c:</strong> Manages the routine of philosophers (eating, thinking, sleeping).</li>
                <li><strong>project_manager.c:</strong> Oversees project execution and flow.</li>
                <li><strong>thread_creation.c:</strong> Manages the creation and handling of threads.</li>
                <li><strong>utils.c & utils2.c:</strong> Provide utility functions used throughout the project.</li>
                <li><strong>program_clean_up.c:</strong> Handles cleanup of processes and resources in the bonus part.</li>
            </ul>
        </div>
        <!-- Key Learning Points -->
        <div id="learning-points" style="background: #ffffff; padding: 20px 30px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);">
            <h2 style="border-bottom: 2px solid #e8491d; padding-bottom: 10px; margin-bottom: 20px; font-size: 24px; font-weight: bold;">📚 Key Learning Points</h2>
            <p>By completing this project, you will:</p>
            <ul>
                <li>Understand the principles of thread management and synchronization.</li>
                <li>Learn how to handle concurrency issues such as race conditions and deadlocks.</li>
                <li>Gain experience with process management and inter-process communication.</li>
                <li>Enhance your problem-solving skills in system programming.</li>
                <li>Develop best practices for writing clean, maintainable code.</li>
            </ul>
            <p>This project will prepare you for real-world challenges in software development and systems programming 🌍.</p>
        </div>
    </div>
    <footer style="text-align: center; padding: 20px; background-color: #35424a; color: white; margin-top: 30px; box-shadow: 0 -2px 4px rgba(0, 0, 0, 0.1);">
        <p>© 2024 Haithem Bendjaballah. All rights reserved.</p>
    </footer>

</body>
</html>
