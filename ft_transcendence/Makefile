DOCKER_COMPOSE = docker-compose
DOCKER_COMPOSE_FILE = ./docker-compose.yml
ENV_FILE = ./.env
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	IP := $(shell ip -4 addr show dev eth0 | grep -oP '(?<=inet\s)\d+(.\d+){3}')
else
	IP := $(shell ipconfig getifaddr en0)
endif

all: up
up: 
	@sed -i "s/BASE_IP=.*/BASE_IP=${IP}/g" ./.env
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) --env-file $(ENV_FILE) up -d --build
down:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) --env-file $(ENV_FILE) down
ps:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) ps

re: clear all

clear: 
		docker-compose down ; docker rm -f $(shell docker ps -a -q) ; docker volume rm $(shell docker volume ls -q)

install: 
		npm install ./src/front;
		npm install ./src/back;


.PHONY: all up down ps