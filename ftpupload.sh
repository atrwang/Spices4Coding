#!/bin/bash
SERVER=“xxxx”
USER=“xxxx”
PASS=“xxxx”
LOCALDIR="/Library/Server/Web/Data/Sites/Default/~kevin"
REMOTEDIR="plaso_website/prod/"

ftp -v -n $SERVER <<END_OF_SESSION
user $USER $PASS
binary
lcd $LOCALDIR
cd $REMOTEDIR
put Dev_Plaso4StudentClientBeta.ipa kevin_DevPlaso4StudentClientBeta.ipa
put Dev_Plaso4TeacherClientBeta.ipa kevin_DevPlaso4TeacherClientBeta.ipa
put Plaso4StudentClientBeta.ipa kevin_Plaso4StudentClientBeta.ipa
put Plaso4TeacherClientBeta.ipa kevin_Plaso4TeacherClientBeta.ipa
bye     
END_OF_SESSION
