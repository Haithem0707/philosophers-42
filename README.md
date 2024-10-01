<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Philo Project Documentation</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            margin: 0;
            padding: 0;
            line-height: 1.6;
        }
        header {
            background: #35424a;
            color: #ffffff;
            padding: 20px 0;
            text-align: center;
        }
        h1, h2, h3, h4 {
            color: #35424a;
        }
        .container {
            width: 80%;
            margin: auto;
            overflow: hidden;
            padding: 30px 0;
        }
        nav {
            background: #35424a;
            color: #ffffff;
            padding: 10px 0;
            text-align: center;
        }
        nav a {
            color: #ffffff;
            padding: 10px 20px;
            text-decoration: none;
        }
        nav a:hover {
            background-color: #e8491d;
            transition: background-color 0.3s;
        }
        .content {
            background: #ffffff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        .section-title {
            border-bottom: 2px solid #e8491d;
            padding-bottom: 10px;
            margin-bottom: 20px;
        }
        ul {
            margin: 0;
            padding: 0;
        }
        ul li {
            list-style: none;
            padding: 10px;
            border-bottom: 1px solid #dddddd;
        }
        ul li:last-child {
            border: none;
        }
        footer {
            text-align: center;
            padding: 20px 0;
            background: #35424a;
            color: #ffffff;
            margin-top: 20px;
        }
    </style>
</head>
<body>
    <header>
        <h1>Philo Project Documentation</h1>
        <p>Welcome to the `philo` project repository! This document provides a detailed overview of the project, covering both the mandatory and bonus parts.</p>
    </header>
    <nav>
        <a href="#overview">Project Overview</a>
        <a href="#mandatory">Mandatory Part</a>
        <a href="#bonus">Bonus Part</a>
        <a href="#structure">Directory Structure</a>
        <a href="#files">File Descriptions</a>
        <a href="#learning">Key Learning Points</a>
        <a href="#testing">Testing Guidelines</a>
    </nav>
    <div class="container">
        <div class="content" id="overview">
            <h2 class="section-title">Project Overview</h2>
            <p>The `philo` project aims to simulate the classic "Dining Philosophers" problem using C. This problem involves philosophers sitting at a table with forks between each of them, where each philosopher must alternate between eating, thinking, and sleeping without causing any deadlock. The project tests your ability to manage synchronization, concurrency, and resource sharing in multi-threaded and multi-process environments.</p>
        </div>
        <div class="content" id="mandatory">
            <h2 class="section-title">Mandatory Part</h2>
            <h3>Goal</h3>
            <p>The goal of the mandatory part is to implement the Dining Philosophers problem using multi-threading. Each philosopher is represented by a thread, and forks are shared resources that must be protected to avoid race conditions.</p>
            <h3>Implementation Details</h3>
            <p>Key considerations include:</p>
            <ul>
                <li>Ensuring no philosopher starves.</li>
                <li>Properly managing mutexes to avoid deadlocks.</li>
                <li>Handling edge cases such as philosophers picking up forks simultaneously.</li>
            </ul>
        </div>
        <div class="content" id="bonus">
            <h2 class="section-title">Bonus Part</h2>
            <h3>Goal</h3>
            <p>The bonus part involves modifying the program to use multi-processes instead of multi-threading. Each philosopher is represented by a process, and inter-process communication is managed using semaphores.</p>
            <h3>Key Differences</h3>
            <ul>
                <li>Processes do not share memory space, so managing shared resources is more complex.</li>
                <li>Additional handling of process termination and cleanup is required.</li>
            </ul>
        </div>
        <div class="content" id="structure">
            <h2 class="section-title">Directory Structure</h2>
            <p>The directory structure for the project is as follows:</p>
            <pre>
├── philo
│   ├── Makefile
│   ├── error_managment.c
│   ├── init_control.c
│   ├── philo_eating.c
│   ├── philo_eating_helper.c
│   ├── philo_header.h
│   ├── philo_int_main.c
│   ├── philos_routine.c
│   ├── project_manager.c
│   ├── thread_creation.c
│   ├── utils.c
│   └── utils2.c
├── philo_bonus
│   ├── Makefile
│   ├── error_managment.c
│   ├── init_control.c
│   ├── philo_header.h
│   ├── philo_int_main.c
│   ├── philos_routine.c
│   ├── program_clean_up.c
│   └── utils.c
            </pre>
        </div>
        <div class="content" id="files">
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
        <div class="content" id="learning">
            <h2 class="section-title">Key Learning Points</h2>
            <p>Through this project, you will learn:</p>
            <ul>
                <li>How to manage threads and processes in C.</li>
                <li>Synchronization techniques using mutexes and semaphores.</li>
                <li>Effective resource management and deadlock prevention.</li>
                <li>Advanced process handling and inter-process communication.</li>
            </ul>
        </div>
        <div class="content" id="testing">
            <h2 class="section-title">Testing Guidelines</h2>
            <p>To ensure your implementation is correct, consider the following testing scenarios:</p>
            <ul>
                <li>No philosopher should starve or die when given sufficient resources.</li>
                <li>Handle edge cases such as when philosophers pick up forks at the same time.</li>
                <li>Test with different numbers of philosophers and eating conditions.</li>
            </ul>
        </div>
    </div>
    <footer>
        <p>&copy; 2024 Philo Project - Documentation by Haithem Bendjaballah</p>
    </footer>
</body>
</html>
