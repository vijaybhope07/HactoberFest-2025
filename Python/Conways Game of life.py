import pygame
import random

pygame.init()

BLACK = (0, 0, 0)
GREY = (40, 40, 40)
YELLOW = (255, 255, 0)
FADE_COLOR = (150, 150, 50)


WIDTH, HEIGHT = 1600, 1000
TILE_SIZE = 20
GRID_WIDTH = WIDTH // TILE_SIZE
GRID_HEIGHT = HEIGHT // TILE_SIZE
FPS = 60

screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()
font = pygame.font.SysFont("consolas", 20, bold=True)

def gen(num):
    return set((random.randrange(GRID_WIDTH), random.randrange(GRID_HEIGHT)) for _ in range(num))

def get_neighbours(pos):
    x, y = pos
    neighbours = []
    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            if dx == 0 and dy == 0:
                continue
            nx, ny = x + dx, y + dy
            if 0 <= nx < GRID_WIDTH and 0 <= ny < GRID_HEIGHT:
                neighbours.append((nx, ny))
    return neighbours

def adjust_grid(positions):
    all_neighbours = set()
    new_positions = set()

    for pos in positions:
        neighbours = get_neighbours(pos)
        all_neighbours.update(neighbours)
        live_neighbours = [n for n in neighbours if n in positions]
        if len(live_neighbours) in [2, 3]:
            new_positions.add(pos)

    for pos in all_neighbours:
        live_neighbours = [n for n in get_neighbours(pos) if n in positions]
        if len(live_neighbours) == 3:
            new_positions.add(pos)

    return new_positions

def draw_grid(positions, fade_dict):
    
    for position in positions:
        col, row = position
        top_left = (col * TILE_SIZE, row * TILE_SIZE)
        pygame.draw.rect(screen, YELLOW, (*top_left, TILE_SIZE, TILE_SIZE))
        fade_dict[position] = 255  

    
    for pos in list(fade_dict.keys()):
        if pos not in positions:
            fade_dict[pos] -= 10
            if fade_dict[pos] <= 0:
                del fade_dict[pos]
            else:
                col, row = pos
                fade = fade_dict[pos]
                color = (fade, fade, 0)
                pygame.draw.rect(screen, color, (col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE))

    
    for row in range(GRID_HEIGHT):
        pygame.draw.line(screen, GREY, (0, row * TILE_SIZE), (WIDTH, row * TILE_SIZE))
    for col in range(GRID_WIDTH):
        pygame.draw.line(screen, GREY, (col * TILE_SIZE, 0), (col * TILE_SIZE, HEIGHT))


def load_pattern(name):
    if name == "glider":
        return {(1, 0), (2, 1), (0, 2), (1, 2), (2, 2)}
    elif name == "blinker":
        return {(10, 10), (11, 10), (12, 10)}
    elif name == "block":
        return {(5, 5), (5, 6), (6, 5), (6, 6)}
    return set()

def main():
    running = True
    playing = False
    count = 0
    update_frequency = 10  
    positions = set()
    fade_dict = {}
    generation = 0

    while running:
        clock.tick(FPS)
        screen.fill(BLACK)

        pygame.display.set_caption(f"{'▶ Playing' if playing else '⏸ Paused'} | Speed: {update_frequency} | Gen: {generation}")

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

            if event.type == pygame.MOUSEBUTTONDOWN:
                x, y = pygame.mouse.get_pos()
                col = x // TILE_SIZE
                row = y // TILE_SIZE
                pos = (col, row)
                if pos in positions:
                    positions.remove(pos)
                else:
                    positions.add(pos)

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    playing = not playing
                if event.key == pygame.K_c:
                    positions = set()
                    fade_dict.clear()
                    generation = 0
                    playing = False
                if event.key == pygame.K_g:
                    positions = gen(random.randrange(4, 10) * GRID_WIDTH)
                    generation = 0
                if event.key == pygame.K_1:
                    positions = load_pattern("block")
                    generation = 0
                if event.key == pygame.K_2:
                    positions = load_pattern("blinker")
                    generation = 0
                if event.key == pygame.K_3:
                    positions = load_pattern("glider")
                    generation = 0
                if event.key == pygame.K_UP:
                    update_frequency = max(1, update_frequency - 1)
                if event.key == pygame.K_DOWN:
                    update_frequency += 1

        
        if playing:
            count += 1
            if count >= update_frequency:
                count = 0
                positions = adjust_grid(positions)
                generation += 1
        draw_grid(positions, fade_dict)
        text = font.render(f"Generation: {generation}", True, (255, 255, 255))
        screen.blit(text, (10, 10))

        pygame.display.update()

    pygame.quit()


if __name__ == "__main__":
    main()