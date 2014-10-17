#!/bin/bash
SERVER="devapp.plaso.cn"
USER="plasoftpuser"
PASS="hongfeizhifei9989"
LOCALDIR="/Library/Server/Web/Data/Sites/Default/tools"
REMOTEDIR="plaso_website/prod/"

ftp -v -n $SERVER <<END_OF_SESSION
user $USER $PASS
$FILETYPE
lcd $LOCALDIR
cd $REMOTEDIR
mput *
mput *.*
bye     
END_OF_SESSION
