<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Philo Project Documentation</title>
    <style>
        body {
            font-family: 'Arial', sans-serif;
            background-color: #f0f4f8;
            margin: 0;
            padding: 0;
            color: #333;
            line-height: 1.6;
        }

header {
            background: #35424a;
            color: #ffffff;
            padding: 30px 0;
            text-align: center;
            margin-bottom: 30px;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
        }
    header h1 {
            margin: 0;
            font-size: 36px;
            font-weight: 400;
        }

 nav {
            background: #35424a;
            color: #ffffff;
            padding: 10px 0;
            text-align: center;
            position: sticky;
            top: 0;
            z-index: 1000;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
        }

  nav a {
            color: #ffffff;
            padding: 10px 20px;
            text-decoration: none;
            font-weight: 500;
        }

 nav a:hover {
            background-color: #e8491d;
            border-radius: 4px;
            transition: background-color 0.3s;
        }

  .container {
            width: 80%;
            margin: auto;
            padding: 20px;
            overflow: hidden;
        }

 .content {
            background: #ffffff;
            padding: 20px 30px;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            margin-bottom: 30px;
        }

 .section-title {
            border-bottom: 2px solid #e8491d;
            padding-bottom: 10px;
            margin-bottom: 20px;
            font-size: 24px;
            font-weight: bold;
        }

 ul {
            margin: 0;
            padding: 0;
        }

 ul li {
            list-style: none;
            padding: 10px 0;
            border-bottom: 1px solid #dddddd;
            font-size: 18px;
        }

  ul li:last-child {
            border: none;
        }

 .code-block {
            background: #f4f4f4;
            padding: 15px;
            margin: 20px 0;
            border-left: 4px solid #35424a;
            overflow-x: auto;
            border-radius: 4px;
            box-shadow: 0 1px 3px rgba(0, 0, 0, 0.1);
        }

 footer {
            text-align: center;
            padding: 20px 0;
            background: #35424a;
            color: #ffffff;
            position: relative;
            bottom: 0;
            margin-top: 20px;
        }

footer p {
            margin: 0;
            font-size: 16px;
        }

.directory-structure {
            white-space: pre;
            background: #f4f4f4;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 1px 3px rgba(0, 0, 0, 0.1);
            margin-bottom: 30px;
        }
    </style>
</head>
<body>
    <header>
        <h1>Philo Project Documentation</h1>
        <p>Comprehensive guide for the Philo project by Haithem Bendjaballah</p>
    </header>
    <nav>
        <a href="#overview">Project Overview</a>
        <a href="#mandatory">Mandatory Part</a>
        <a href="#bonus">Bonus Part</a>
        <a href="#structure">Directory Structure</a>
        <a href="#file-descriptions">File Descriptions</a>
        <a href="#learning-points">Key Learning Points</a>
        <a href="#testing">Testing Guidelines</a>
    </nav>
    <div class="container">
        <div id="overview" class="content">
            <h2 class="section-title">Project Overview</h2>
            <p>The `philo` project aims to simulate the classic "Dining Philosophers" problem using C. This problem involves philosophers sitting at a table with forks between each of them, where each philosopher must alternate between eating, thinking, and sleeping without causing any deadlock. The project tests your ability to manage synchronization, concurrency, and resource sharing in multi-threaded and multi-process environments.</p>
        </div>
        <div id="mandatory" class="content">
            <h2 class="section-title">Mandatory Part</h2>
            <p><strong>Goal:</strong> The goal of the mandatory part is to implement the Dining Philosophers problem using multi-threading. Each philosopher is represented by a thread, and forks are shared resources that must be protected to avoid race conditions.</p>
            <div class="code-block">
                <pre>
Key considerations include:
- Ensuring no philosopher starves.
- Properly managing mutexes to avoid deadlocks.
- Handling edge cases such as philosophers picking up forks simultaneously.
                </pre>
            </div>
        </div>
        <div id="bonus" class="content">
            <h2 class="section-title">Bonus Part</h2>
            <p><strong>Goal:</strong> The bonus part involves modifying the program to use multi-processes instead of multi-threading. Each philosopher is represented by a process, and inter-process communication is managed using semaphores.</p>
            <div class="code-block">
                <pre>
Key Differences:
- Processes do not share memory space, so managing shared resources is more complex.
- Additional handling of process termination and cleanup is required.
                </pre>
            </div>
        </div>
        <div id="structure" class="content">
            <h2 class="section-title">Directory Structure</h2>
            <div class="directory-structure">
                ├── philo<br>
                │   ├── Makefile<br>
                │   ├── error_managment.c<br>
                │   ├── init_control.c<br>
                │   ├── philo_eating.c<br>
                │   ├── philo_eating_helper.c<br>
                │   ├── philo_header.h<br>
                │   ├── philo_int_main.c<br>
                │   ├── philos_routine.c<br>
                │   ├── project_manager.c<br>
                │   ├── thread_creation.c<br>
                │   ├── utils.c<br>
                │   └── utils2.c<br>
                ├── philo_bonus<br>
                │   ├── Makefile<br>
                │   ├── error_managment.c<br>
                │   ├── init_control.c<br>
                │   ├── philo_header.h<br>
                │   ├── philo_int_main.c<br>
                │   ├── philos_routine.c<br>
                │   ├── program_clean_up.c<br>
                │   └── utils.c<br>
            </div>
        </div>
        <div id="file-descriptions" class="content">
            <h2 class="section-title">Detailed File Descriptions</h2>
            <ul>
                <li><strong>Makefile:</strong> Contains build instructions for the project.</li>
                <li><strong>error_management.c:</strong> Handles error reporting and management.</li>
                <li><strong>init_control.c:</strong> Initializes control structures for threads or processes.</li>
                <li><strong>philo_eating.c / philo_eating_helper.c:</strong> Manages the eating behavior of philosophers.</li>
                <li><strong>philo_header.h:</strong> Header file containing shared declarations.</li>
                <li><strong>philo_int_main.c:</strong> The main entry point for the program.</li>
                <li><strong>philos_routine.c:</strong> Implements the main routine for philosophers (eating, sleeping, thinking).</li>
                <li><strong>project_manager.c:</strong> Manages project-level operations and structures.</li>
                <li><strong>thread_creation.c:</strong> Handles the creation and management of threads.</li>
                <li><strong>utils.c / utils2.c:</strong> Contains utility functions for common operations.</li>
            </ul>
        </div>
        <div id="learning-points" class="content">
            <h2 class="section-title">Key Learning Points</h2>
            <ul>
                <li>How to manage threads and processes in C.</li>
                <li>Synchronization techniques using mutexes and semaphores.</li>
                <li>Effective resource management and deadlock prevention.</li>
                <li>Advanced process handling and inter-process communication.</li>
            </ul>
        </div>
        <div id="testing" class="content">
            <h2 class="section-title">Testing Guidelines</h2>
            <p>Test the project with various scenarios such as different numbers of philosophers, varying time intervals, and forced deadlock conditions. Ensure the following:</p>
            <ul>
                <li>No philosopher should starve or die in scenarios designed to keep them alive.</li>
                <li>Deadlock should be prevented in all cases.</li>
                <li>Output should be accurate and follow the expected format.</li>
            </ul>
        </div>
    </div>
    <footer>
        <p>Philo Project Documentation by Haithem Bendjaballah &copy; 2024</p>
    </footer>
</body>
</html>
