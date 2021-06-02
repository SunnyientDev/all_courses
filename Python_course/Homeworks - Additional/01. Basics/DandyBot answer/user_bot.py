import random_bot

def script(check, x, y):
    # first level
    if check("level") == 1:
        # Method: go to the right and then down (if we met a wall)
        if check("gold", x, y):
            return "take"
        elif check("wall", x + 2, y): # wall
            return "down"
        return "right"

    # second level
    if check("level") == 2:
        # Method: go forward and then follow the trajectory of gold
        if check("gold", x, y): # Just taking one coin
            return "take"

        if check("gold", x + 1, y): # The coin is on right? - Go there
            return  "right"
        elif check("gold", x - 1, y): # The coin is on left? - Go there
            return  "left"
        
        if check("gold", x, y - 1):
            return  "up"
        elif check("gold", x, y + 1):
            return  "down"

        if not check("wall", x + 2, y):
            return "right"
    
        return "up"

    # third level
    if check("level") == 3:
        wall_above = check("wall", x, y + 1)
        wall_above_right = check("wall", x + 1, y + 1)
        wall_above_left = check("wall", x - 1, y + 1)

        wall_under = check("wall", x, y - 1)
        wall_under_right = check("wall", x + 1, y - 1)
        wall_under_left = check("wall", x - 1, y - 1)

        wall_right = check("wall", x + 1, y)
        wall_left = check("wall", x - 1, y)

        if check("gold", x, y):
            return "take"
        if wall_left and wall_above:
            return "right"
        if wall_right and wall_above:
            return "up"
        if wall_under and wall_right:
            return "left"
        if wall_left and wall_under:
            return "down"
        if wall_above:
            return "right"
        if wall_right:
            return "up"
        if wall_under:
            return "left"
        if wall_left:
            return "down"
        if wall_under_right:
            return "up"
        if wall_above_right:
            return "right"
        if wall_above_left:
            return "down"
        if wall_under_left:
            return "left"
    
    # fourth level
    if check("level") == 4:
        wall_above = check("wall", x, y + 1)
        wall_above_right = check("wall", x + 1, y + 1)
        wall_above_left = check("wall", x - 1, y + 1)

        wall_under = check("wall", x, y - 1)
        wall_under_right = check("wall", x + 1, y - 1)
        wall_under_left = check("wall", x - 1, y - 1)

        wall_right = check("wall", x + 1, y)
        wall_left = check("wall", x - 1, y)

        if check("gold", x, y):
            return "take"
        if check("wall", x, y - 2) and check("wall", x + 1, y - 2) and check("wall", x + 2, y - 2) and check("wall", x, y + 1):
            return "up"
        if check("wall", x - 2, y + 2) and check("wall", x - 1, y + 2) and check("wall", x, y + 2) and check("wall", x, y - 1):
            return "down"
        
        if wall_left and wall_above:
            return "right"
        if wall_right and wall_above:
            return "up"
        if wall_under and wall_right:
            return "left"
        if wall_left and wall_under:
            return "down"
        if wall_above:
            return "right"
        if wall_right:
            return "up"
        if wall_under:
            return "left"
        if wall_left:
            return "down"
        if wall_under_right:
            return "up"
        if wall_above_right:
            return "right"
        if wall_above_left:
            return "down"
        if wall_under_left:
            return "left"
    return "pass"