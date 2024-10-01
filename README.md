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
        <a href="#file-descriptions" style="color: #ffffff; padding: 10px 20px; text-decoration: none; font-weight: 500;">🗃️ File Descriptions</a>
        <a href="#learning-points" style="color: #ffffff; padding: 10px 20px; text-decoration: none; font-weight: 500;">📚 Key Learning Points</a>
        <a href="#testing" style="color: #ffffff; padding: 10px 20px; text-decoration: none; font-weight: 500;">✅ Testing Guidelines</a>
    </nav>
    <div style="width: 80%; margin: auto; padding: 20px; overflow: hidden;">
        <div id="overview" style="background: #ffffff; padding: 20px 30px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); margin-bottom: 30px;">
            <h2 style="border-bottom: 2px solid #e8491d; padding-bottom: 10px; margin-bottom: 20px; font-size: 24px; font-weight: bold;">📖 Project Overview</h2>
            <p>The `philo` project aims to simulate the classic "Dining Philosophers" problem 🍽️. This problem involves philosophers 🧠 sitting at a table with forks 🍴 between each of them, where each philosopher must alternate between eating 🍝, thinking 💭, and sleeping 💤 without causing any deadlock. The project tests your ability to manage synchronization 🔄, concurrency 🔀, and resource sharing in multi-threaded and multi-process environments.</p>
        </div>
        <div id="mandatory" style="background: #ffffff; padding: 20px 30px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); margin-bottom: 30px;">
            <h2 style="border-bottom: 2px solid #e8491d; padding-bottom: 10px; margin-bottom: 20px; font-size: 24px; font-weight: bold;">🛠️ Mandatory Part</h2>
            <p><strong>Goal:</strong> The goal of the mandatory part is to implement the Dining Philosophers problem using multi-threading 🧵. Each philosopher is represented by a thread, and forks are shared resources that must be protected to avoid race conditions ⚠️.</p>
            <div style="background: #f4f4f4; padding: 15px; margin: 20px 0; border-left: 4px solid #35424a; overflow-x: auto; border-radius: 4px; box-shadow: 0 1px 3px rgba(0, 0, 0, 0.1);">
                <pre>
Key considerations include:
- Ensuring no philosopher starves 🚫.
- Properly managing mutexes 🔒 to avoid deadlocks ❌.
- Handling edge cases such as philosophers picking up forks simultaneously ⏱️.
                </pre>
            </div>
        </div>
        <div id="bonus" style="background: #ffffff; padding: 20px 30px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); margin-bottom: 30px;">
            <h2 style="border-bottom: 2px solid #e8491d; padding-bottom: 10px; margin-bottom: 20px; font-size: 24px; font-weight: bold;">🚀 Bonus Part</h2>
            <p><strong>Goal:</strong> The bonus part involves modifying the program to use multi-processes instead of multi-threading 🚦. Each philosopher is represented by a process, and inter-process communication is managed using semaphores 📊.</p>
            <div style="background: #f4f4f4; padding: 15px; margin: 20px 0; border-left: 4px solid #35424a; overflow-x: auto; border-radius: 4px; box-shadow: 0 1px 3px rgba(0, 0, 0, 0.1);">
                <pre>
Key Differences:
- Processes do not share memory space 🧠, so managing shared resources is more complex 🔄.
- Additional handling of process termination and cleanup 🧹 is required.
                </pre>
            </div>
        </div>
        <div id="structure" style="background: #ffffff; padding: 20px 30px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); margin-bottom: 30px;">
            <h2 style="border-bottom: 2px solid #e8491d; padding-bottom: 10px; margin-bottom: 20px; font-size: 24px; font-weight: bold;">📂 Directory Structure</h2>
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
        </div>
        <div id="file-descriptions" style="background: #ffffff; padding: 20px 30px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); margin-bottom: 30px;">
            <h2 style="border-bottom: 2px solid #e8491d; padding-bottom: 10px; margin-bottom: 20px; font-size: 24px; font-weight: bold;">🗃️ Detailed File
