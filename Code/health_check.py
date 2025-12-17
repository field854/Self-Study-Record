import os
#check  whether the files exists
file_path = input("Please enter the path like:\"Code/disk_usage_report.sh\"\n:"
)

if os.path.exists(file_path):
    print(f"find the script: {file_path}")
    # check whether there is execution perssion
    if os.access(file_path,os.X_OK):
        print("This script has been authorized.")
    else:
        print("Warning:This script lacks permission.")
else:
    print("Error:Can't find the file" \
    "{file_path}")        