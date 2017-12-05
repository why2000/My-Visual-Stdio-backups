import sys
import pygame
from settings import Settings
from ship import Ship


def run_game():

    pygame.init()
    ui_settings = Settings()
    screen = pygame.display.set_mode(
        (ui_settings.screen_width, ui_settings.screen_height))
    pygame.display.set_caption("Alien Invasion")
    screen.fill(ui_settings.bg_color)
    ship = Ship(screen)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
        
        pygame.display.flip()
        ship.blitme()


run_game()
