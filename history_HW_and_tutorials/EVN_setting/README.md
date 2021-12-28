# Environment Setting
## Important Links
* [Gitlab](https://ssl-gitlab.csie.ntut.edu.tw): https://ssl-gitlab.csie.ntut.edu.tw

* [Jenkins](https://ssl-jenkins.csie.ntut.edu.tw): https://ssl-jenkins.csie.ntut.edu.tw


## Category
1. [Gitlab Setting](#gitlab-setting)
2. [Computer Environment Setting](./computer_environment_setting.md)
3. [Homework Upload Tutorial](./homework_upload_tutorial.md)

## Gitlab Setting

### 1. Go to your t${STUDENT_ID}@ntut.org.tw to check your gitlab mail, and set your password.

### 2. Go to [NTUT ssl gitlab](https://ssl-gitlab.csie.ntut.edu.tw), and try to login the account.
  ![Login](./img/gitlab/signIn.png)

### 3. Select "Create a project" to create a new project.

**Important**:
  1. The project name must to be **${COURSE_NAME}_${STUDENT_ID}_HW**.
        ```
        ${COURSE_NAME}:
        Pattern Oriented Software Design in 2021 fall: `posd2021f`

        ${STUDENT_ID}:
        Your student id, like `106820000`
        ```

  2. Set project visibility level as **private**.
    ![Select Create Project](./img/gitlab/selectCreate.png)
    ![Create Project](./img/gitlab/createProject.png)

### 3. Set webhook

1. Go to **Setting -> Webhooks**<br>
    ![gitlab integration](./img/gitlab/gitlabWebhook.png)

2. Fill in url as: "https://root:116a1516a5e2f5ec4026a208654b9e4d04@ssl-jenkins.csie.ntut.edu.tw/project/${COURSE_NAME}_${STUDENT_ID}_HW"
    ```
      ${COURSE_NAME}:
      Pattern Oriented Software Design in 2021 fall: `posd2021f`

      ${STUDENT_ID}:
      Your student id, like `106820000`
    ```


3. Keep Secret Token as empty.

4. Select **Push events** in Trigger selection

5. Unselect **Enable SSL verification** in SSL verification.

6. Click "Add webhook"
  ![webhook](./img/gitlab/webhookSetting.png)
