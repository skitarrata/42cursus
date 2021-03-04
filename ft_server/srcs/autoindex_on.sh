sed -i -e '/index/s/ index.nginx-debian.html;/; #index.nginx-debian.html/' etc/nginx/sites-available/default
sed -i -e '/autoindex/s/off/on/' etc/nginx/sites-available/default
service nginx reload
