import pygame

pygame.init()
screen=pygame.display.set_mode((800,600))

background = pygame.image.load("background.png")
icon = pygame.image.load("spaceship.png")

pygame.display.set_caption("space invador")
pygame.display.set_icon(icon)

while True:
    screen.blit(background,(120,100))
    pygame.display.update()