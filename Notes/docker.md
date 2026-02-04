一、 服务启动与用户权限
在使用 Docker 命令之前，需要确保服务已启动且用户有相应权限。
• docker version 或 docker info
    ◦ 用法： 安装完成后运行。
    ◦ 意义： 验证 Docker 是否安装成功。
• sudo usermod -aG docker $USER
    ◦ 用法： 将当前用户加入 Docker 用户组。
    ◦ 意义： 避免每次运行 docker 命令都需要输入 sudo。需注销并重新登录（或重启）生效。
• sudo service docker start
    ◦ 用法： 使用 service 命令启动服务。
    ◦ 意义： 启动 Docker 后台服务。
• sudo systemctl start docker
    ◦ 用法： 使用 systemctl 命令启动服务。
    ◦ 意义： 启动 Docker 后台服务（适用于大多数现代 Linux 发行版）。
• docker login
    ◦ 用法： 在命令行输入。
    ◦ 意义： 登录 Docker 账户（如 Docker Hub），以便发布镜像。

--------------------------------------------------------------------------------
二、 镜像管理 (Image Management)
Docker 镜像（Image）是应用程序及其依赖的打包文件，是容器的模板。
• docker image pull [library/][imageName]
    ◦ 用法： 例如 docker image pull hello-world。
    ◦ 意义： 从远程仓库（默认为 Docker Hub）抓取镜像到本地。如果省略组名 library，默认为官方镜像组,。
• docker image ls
    ◦ 用法： 直接运行。
    ◦ 意义： 列出本机所有的 image 文件。
    ◦ 备注： 评论区指出旧版本或简写命令为 docker images。
• docker image rm [imageName]
    ◦ 用法： 指定镜像名进行删除。
    ◦ 意义： 删除本机的 image 文件。
• docker image build -t [name]:[tag] .
    ◦ 用法： 例如 docker image build -t koa-demo:0.0.1 .。
    ◦ 意义： 根据当前目录（.）下的 Dockerfile 构建 image 文件。-t 指定名称和标签（默认为 latest）。
• docker image tag [imageName] [username]/[repository]:[tag]
    ◦ 用法： 为本地镜像打标签。
    ◦ 意义： 为了发布到仓库，给镜像标注用户名和版本。
• docker image push [username]/[repository]:[tag]
    ◦ 用法： 推送镜像。
    ◦ 意义： 将制作好的 image 文件发布到网上仓库（如 Docker Hub）。

--------------------------------------------------------------------------------
三、 容器管理 (Container Management)
容器（Container）是镜像运行时的实例。
1. 创建与启动
• docker container run [imageName]
    ◦ 用法： 从 image 生成并运行一个容器实例。如果本地没有该 image，会自动抓取。
    ◦ 常用参数：
        ▪ -p [host_port]:[container_port]：端口映射。将容器端口映射到本机端口（例如 -p 8000:3000）。
        ▪ -it：交互模式。将容器的 Shell 映射到当前 Shell，以便在容器内执行命令。
        ▪ --rm：运行结束后自动清理。容器停止运行后自动删除容器文件。
        ▪ [command]：例如 /bin/bash，指定容器启动后内部执行的第一个命令。
• docker container start [containerID]
    ◦ 用法： 指定容器 ID。
    ◦ 意义： 启动一个已经生成但已停止运行的容器文件，避免重复新建容器。
2. 查看与监控
• docker container ls
    ◦ 用法： 直接运行。
    ◦ 意义： 列出本机正在运行的容器。
    ◦ 备注： 评论区指出常用简写为 docker ps；docker container ls -l 可查看最近创建的容器。
• docker container ls --all
    ◦ 用法： 带 --all 参数。
    ◦ 意义： 列出本机所有容器，包括已经终止运行的容器。
    ◦ 备注： 评论区指出常用简写为 docker ps -a。
• docker container logs [containerID]
    ◦ 用法： 查看指定容器日志。
    ◦ 意义： 查看容器的标准输出（stdout），常用于后台运行模式下的调试。
• docker container stats (来自评论区)
    ◦ 意义： 查看容器的资源使用状态。
3. 停止与删除
• docker container kill [containerID]
    ◦ 用法： 强行终止。
    ◦ 意义： 向容器主进程发送 SIGKILL 信号，立即终止运行，操作可能丢失,。
• docker container stop [containerID]
    ◦ 用法： 正常停止。
    ◦ 意义： 向容器主进程发送 SIGTERM 信号（允许收尾清理），过一段时间再发送 SIGKILL。比 kill 更温和。
    ◦ 注意： 教程原文中有笔误写成了 bash container stop，后在评论区被指正为 docker container stop,。
• docker container rm [containerID]
    ◦ 用法： 指定 ID 删除。
    ◦ 意义： 删除已停止运行的容器文件，释放硬盘空间。
4. 交互与操作
• docker container exec -it [containerID] /bin/bash
    ◦ 用法： 进入容器。
    ◦ 意义： 进入一个正在运行的容器，并启动 Shell 进行操作。
• docker container cp [containerID]:[path] .
    ◦ 用法： 拷贝文件。
    ◦ 意义： 从正在运行的容器中将文件拷贝到本机当前目录。

--------------------------------------------------------------------------------
四、 Dockerfile 语法
Dockerfile 是用于配置和构建 Image 的文本文件。
• FROM：指定基础镜像（例如 FROM node:8.4），继承其环境。
• COPY：将文件从本机拷贝到镜像内（例如 COPY . /app）。
• WORKDIR：指定接下来的工作路径（例如 WORKDIR /app）。
• RUN：在构建阶段（Build）执行的命令（例如 npm install），结果会被打包进镜像,。
• EXPOSE：声明容器暴露的端口（例如 EXPOSE 3000），允许外部连接。
• CMD：指定容器启动后（Run）自动执行的命令（例如 CMD node demos/01.js）。一个 Dockerfile 只能有一个 CMD，且会被 docker run 后面的命令覆盖。
• .dockerignore（文件）：指定构建时排除的路径，不打包进入 image。
总结
这些命令涵盖了 Docker 的全生命周期：从环境配置、镜像的获取与构建（Build），到容器的创建、运行（Run）、停止与销毁。用户可以通过 Dockerfile 定制环境，通过 image 分发环境，通过 container 运行环境。