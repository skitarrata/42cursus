#Creo certificato SSL
mkdir etc/nginx/ssl
openssl req -x509 -sha256 -nodes -days 365 -subj "/C=IT/ST=Italy/L=Rome/O=42Roma/OU=svalenti/CN=localhost" -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx-selfsigned.key -out /etc/nginx/ssl/nginx-selfsigned.pem

#Avvio i servizi
service nginx start
service mysql start
service php7.3-fpm start

#Creo database wordpress
echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password

bash
