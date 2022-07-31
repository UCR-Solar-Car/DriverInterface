# Driver-Interface-2022

Welcome to the Driver Interface for UCR Solar Car 2023! The driver interface is run with QT C++ to create an 
interactive GUI display to display various kinds of system critical information. 

## Repository Setup 
`dev` branch represents a developer's environment where we can test out new features, changes without affecting 
the version that the solar car will be using. 

`main` branch represents the version that the solar car will be running! Changes to this branch must be checked to
ensure no errors, hence the `dev` branch. Everytime the Raspberry Pi is started, it will run the `driverinterface.sh` 
script which will update the local repository to include any new changes and then proceed to compile the project.  

## Contribution/Development

Run the following command to obtain a local copy of this repository! This only needs to happen once! 
```
git clone https://github.com/UCR-Solar-Car/Driver-Interface-2022.git
``` 

Check out the [issues](https://github.com/UCR-Solar-Car/Driver-Interface-2022/issues) tab to see current thats that need to be worked on! 
Issues have various labels to help us organize their priority and workload. `LIGHTWORK` and `HEAVYWORK` estimate the 
research and workload required to complete the issue. `LOW`, `MEDIUM`, `HIGH` represent the priority levels. `HIGH` and `MEDIUM` are issues
that need to be completed in order for the Solar Car to work efficiently. `LOW` represents small bugs/issues/inconviences that will usually not affect
the overall performace or output of the application. 

Once you have chosen an issue to work on, create a branch using the following naming convention `github_username/feature_name` (ie `ucrsolarcar/add_icons`).
This will help organize who has worked on what code and ensure we are accountable for our code. Once you have pushed your code to Github, create a 
[pull request](https://github.com/UCR-Solar-Car/Driver-Interface-2022/pulls) and send it in the #updates channel in the Software Category. Ensure that you
link the pull request with the corresponding issue so we know which issue your code solves. Ensure that you fix any merge conflicts, if they should arise. 
After you have gotten your reviews, you may merge your code and the branch will automatically delete. The issue should automatically close as well. 

## References 

### Git Commands
Use the following command to create a new branch and checkout to said branch. 
```
git checkout -b <branch_name> 
```
OR
```
git branch <branch_name>
git checkout <branch_name>
```

Use the following command to track all files for git to keep track of. 
```
git add .
```

Use the following command to commit your changes! Note: this will not push code to your remote branch! 
```
git commit -m "useful_message"
```

Use the following command to push your changes to your remote branch!
```
git push origin <branch_name>
```

### QT Installation and setup
In order for you to run and test out your code, ensure that you have QT installed. You can find the installation link 
[here](https://www.qt.io/download-open-source?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5)!
Scroll down to the `DOWNLOAD THE QT ONLINE INSTALLER` which should navigate you to a page to download the installer. 

Once downloaded, run the installer (this will take a while). Accept the terms, and you will be required to make a QT account (free!), 
it does not matter whether you use your personal or school email. It will then proceed to ask you what you would like to install, ensure that
you select `QT for Desktop` and `QT Design Studio`, `QT for Mobile Applications` is not required but you may install it if you desire. 

Once installed, open `QT Creator` (it would be best to create a shortcut to access) and click `Open Project`, navigate to the `Driver-Interface-2022` 
and select the `DriverInterface.pro` file, ensure that QT for Desktop (may specify operating system instead of Desktop) and click configure. QT will
provide you with a text editor for you to edit code. To run/test your code, click on the green run button in the lower-left-hand corner, this will compile
the application and open the application. Make sure to close your app instances, as it will create a new instance each time you run your code. 
