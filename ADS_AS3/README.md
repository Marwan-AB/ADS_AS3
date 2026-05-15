<h2 align="center">CSCE 2211 Fall 2025 Applied Data Structures</h2>
<h3 align="center">Assignment #5</h3>

> [!IMPORTANT]  
> Avoid deduction by writing your name, section number, and ID in a comment at the beginning of each file, then push your changes. 📝

<table border="0">
 <tr>
    <td><b style="font-size:20px">📋 Prerequisites for the Assignment</b></td>
    <td><b style="font-size:20px">🛠️ How It Works (Testing Cases)</b></td>
 </tr>
 <tr>
    <td>
    1. Create a <a href="https://account.jetbrains.com/login" target="_blank">JetBrains Account</a> & apply for the student pack. 🎓<br>    
    2. Download <a href="https://www.jetbrains.com/clion/download/#section=mac" target="_blank">CLion for Windows & Mac</a> and sign in with your account. 💻<br>    
    3. Sign in to the GitHub Desktop app on your PC. 🔗<br>  
    4. Clone this repository to start working on the assignment. 📂<br>
    5. Write your name and ID in a comment at the beginning of each file, then push your changes. 📝<br>
    </td>
    <td>
    1. Open the repo folder as a project in CLion IDE. 🚀<br> 
    2. Start writing your code in the <strong>Code_library</strong> directory. 🖊️<br>
    3. After completing the required parts, go to <strong>Google_tests</strong> and run <strong>TestBTree</strong> to test your code. 🧪<br>
    4. The test suite files will show which tests have passed and which have failed. ✅❌<br>
    </td>
 </tr>
</table>

> [!WARNING]
> - Your submission time affects the assignment grade; pay attention to your deadlines.
> - You must commit and push your code to GitHub at the end of each change.

---

## 🔍 Overview of the Exercise
In this exercise, you will implement a **Dijkstra + Floyd–Warshall** in C++.  


You will:
1. Load a weighted directed graph from a text file.
2. Implement Dijkstra and Floyd–Warshall inside the provided function skeletons.
3. Call Dijkstra repeatedly (one run per node) to produce an All-Pairs Shortest Path (APSP) output.
4. Verify correctness of outputs using provided GoogleTest testcases

---

## 🧪 Testing Your Code
- Run the tests (Google_tests/Testcases.cpp).
- Ensure all unit tests pass before submission.

---

### 📬 Submission Instructions
- Comment your code and document any assumptions you made.
- Do not leave `TODO` sections empty.
- Ensure your program compiles and runs correctly in CLion.
- Push your final solution to GitHub before the deadline.

---

📝 To-Do List
- [ ] Implement `dijkstra(int src)`.
- [ ] Implement `repeatedDijkstra() `.
- [ ] Implement `floydWarshall()`.
- [ ] Run all test cases successfully.
- [ ] Commit and push your code regularly to GitHub.

:white_check_mark: Use `git status` to list all new or modified files that haven’t yet been committed.
