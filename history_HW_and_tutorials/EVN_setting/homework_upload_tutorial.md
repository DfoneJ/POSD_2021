# Homework Upload Tutorial

## Category
* [First Setting](#first-setting)
* [Upload Homework](#upload-homework)
* [Check homework status](#check-homework-status)

## First Setting
**Note**: Only first time needs to do setting
1. Make the project directory on your pc.<br>
    ![mkdir](./img/homework/mkdir.png)

2. Open the terminal and enter the following command.<br>
    Get in to project directory and initialize as git project.
    ```shell
    $ cd /path/to/your/project
    $ git init
    ```
    ![git init](./img/homework/gitInit.png)

3. Go to [Gitlab](https://ssl-gitlab.csie.ntut.edu.tw) to find your own project link.<br>
    **Suggestion**: Use https link instead of ssh link.
    ![repoLink](./img/homework/repoLink.png)

4. Link your git project to Gitlab repository.<br>
    Enter following command:
    ```shell
    $ git remote add origin ${YOUR_URL}
    ```
   ** Replace ${YOUR_URL} with the gitlab project link from step 3.<br>
   ![Add origin](./img/homework/AddOrigin.png)

## Upload Homework
1. Look up the current status of git repository.<br>
    Enter following command:
    ```shell
    $ git status
    ```
    ![Git status](./img/homework/GitStatus.png)

2. Add the new/modified files to "Changes to be committed" queue:<br>
    Enter following command:
    ```shell
    $ git add .
    ```
    ![Git Add](./img/homework/gitAdd.png)<br>
    If the file status is "deleted", you'll need rm command:
    ```shell
    $ git rm ${FILE_NAME}
    ```
    ![Git rm](./img/homework/gitRm.png)

3. Check the current status again.
    ```shell
    $ git status
    ```
    ![Git status 2](./img/homework/GitStatus2.png)

4. If the status in step 3 is correct, you can commit the current changes to git history.<br>
    By following command:
    ```shell
    $ git commit -m "${YOUR_COMMIT_MESSAGE}"
    ```
    ${YOUR_COMMIT_MESSAGE} is the message to describe the current changes you commit.<br>
    ![Git Commit](./img/homework/gitCommit.png)<br>
    **Note**: If it's your first time to commit in your device, system will require you to provide your personal info.<br>
    Enter the following commands to fill in infos.
    ```shell
    $ git config --global user.email ${YOUR_EMAIL}
    $ git config --global user.name ${YOUR_NAME}
    ```
    Then you can enter the commit message in step 4 again.

5. Push your local commits to Gitlab server.<br>
    Enter the following command:
    ```shell
    $ git push -u origin master
    ```
    And enter your username & password.<br>
    ** The password won't show when you enter.<br>
    ![Git push](./img/homework/gitPush.png)

## Check homework status
1. Go to [Gitlab](https://ssl-gitlab.csie.ntut.edu.tw) to check your upload status.<br>
    ![Gitlab status](./img/homework/GitlabStatus.png)

2. Go to [Jenkins](https://ssl-jenkins.csie.ntut.edu.tw) to check your homework status.<br>
    The username and password are default in your **student ID**<br>
    For example, username: `106820000`, password: `106820000`<br>
    Please login and modified to your own password

    Projects to check:
    * Check ${COURSE}_${STUDENT_ID}_HW, for example: `posd2021s_106820000_HW`.<br>
      This project is for executing student's own unit tests.
    * Check ${COURSE}_${STUDENT_ID}_HW_TA, for example: `posd2021s_106820000_HW_TA`.<br>
      This project is for executing TA provided unit tests.

    Project status:
    * Blue: all unit tests passed.
    * Red: some tests failed, or compile failed.
    ![Jenkins Status](./img/homework/JenkinsStatus.png)

    If you click blue/red light, you can see the execution console to check execution status.
    ![Jenkins Console](./img/homework/JenkinsConsole.png)