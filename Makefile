# Colors
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
CYAN	= \033[0;36m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
NC		= \033[0m # No Color

NAME					= cub3D
BONUS					= cub3D_bonus

CC						= cc
CFLAGS					= -Wall -Wextra -Werror -g  #-fsanitize=address

# ===== MLX42 & GLFW LIBRARIES 

LIBMLX					= $(HOME)/MLX42
MLX_INCLUDE				= $(HOME)/MLX42/include/MLX42
MLX_LIB					= $(HOME)/MLX42/build/libmlx42.a
GLFW_INCLUDE			= $(HOME)/.brew/include
GLFW_LIB				= $(HOME)/.brew/lib

HEADERS					= -I ./inc -I $(MLX_INCLUDE) -I $(GLFW_INCLUDE)

HEADER_FILES			= inc/cub3d.h
HEADER_FILES_BONUS		= inc/cub3d_bonus.h

LIBS					= $(MLX_LIB) -L $(GLFW_LIB) -lglfw -framework OpenGL -framework IOKit -framework Cocoa

# ===== MANDATORY SOURCES =====

SRCS_MANDATORY			= \
	src_mandatory/main.c \
	src_mandatory/main_utils.c \
	src_mandatory/engine/init_game.c \
	src_mandatory/engine/init_game_utils.c \
	src_mandatory/engine/init_setup_1.c \
	src_mandatory/engine/init_setup_2.c \
	src_mandatory/engine/input.c \
	src_mandatory/engine/input_utils.c \
	src_mandatory/engine/movement.c \
	src_mandatory/engine/keys.c \
	src_mandatory/engine/keys_utils.c \
	src_mandatory/engine/math_utils.c \
	src_mandatory/engine/raycasting.c \
	src_mandatory/engine/raycasting_utils_1.c \
	src_mandatory/engine/raycasting_utils_2.c \
	src_mandatory/engine/rendering.c \
	src_mandatory/engine/rendering_utils.c \
	src_mandatory/engine/textures.c \
	src_mandatory/engine/textures_utils_1.c \
	src_mandatory/engine/textures_utils_2.c \
	src_mandatory/parsing/parse_file.c \
	src_mandatory/parsing/parse_file_content_1.c \
	src_mandatory/parsing/parse_file_content_2.c \
	src_mandatory/parsing/parse_file_content_3.c \
	src_mandatory/parsing/parse_map_1.c \
	src_mandatory/parsing/parse_map_2.c \
	src_mandatory/parsing/parse_map_3.c \
	src_mandatory/parsing/parse_rgb_1.c \
	src_mandatory/parsing/parse_rgb_3.c \
	src_mandatory/parsing/parse_textures_1.c \
	src_mandatory/parsing/parse_textures_2.c \
	src_mandatory/parsing/validate_map_1.c \
	src_mandatory/parsing/validate_map_2.c \
	src_mandatory/parsing/validate_map_3.c \
	src_mandatory/parsing/validate_map_4.c \
	src_mandatory/parsing/validate_map_5.c \
	src_mandatory/utils/error.c \
	src_mandatory/utils/utils_1.c \
	src_mandatory/utils/utils_2.c \
	src_mandatory/utils/utils_3.c \
	src_mandatory/utils/utils_4.c \
	src_mandatory/utils/utils_5.c \
	src_mandatory/utils/utils_6.c \
	src_mandatory/utils/utils_7.c \
	src_mandatory/utils/free.c

# ===== BONUS SOURCES =====

SRCS_BONUS				= \
	src_bonus/main_bonus.c \
	src_bonus/main_utils_bonus.c \
	src_bonus/animation/anim_0_bonus.c \
	src_bonus/animation/anim_1_bonus.c \
	src_bonus/animation/anim_2_bonus.c \
	src_bonus/animation/anim_3_bonus.c \
	src_bonus/animation/anim_4_bonus.c \
	src_bonus/animation/anim_5_bonus.c \
	src_bonus/engine/init_game_bonus.c \
	src_bonus/engine/init_game_utils_bonus.c \
	src_bonus/engine/init_setup_1_bonus.c \
	src_bonus/engine/init_setup_2_bonus.c \
	src_bonus/engine/input_bonus.c \
	src_bonus/engine/input_utils_bonus.c \
	src_bonus/engine/movement_bonus.c \
	src_bonus/engine/keys_bonus.c \
	src_bonus/engine/keys_utils_bonus.c \
	src_bonus/engine/math_utils_bonus.c \
	src_bonus/engine/raycasting_bonus.c \
	src_bonus/engine/raycasting_utils_1_bonus.c \
	src_bonus/engine/raycasting_utils_2_bonus.c \
	src_bonus/engine/rendering_bonus.c \
	src_bonus/engine/render_anim_1_bonus.c \
	src_bonus/engine/render_anim_2_bonus.c \
	src_bonus/engine/rendering_utils_bonus.c \
	src_bonus/engine/textures_bonus.c \
	src_bonus/engine/textures_utils_1_bonus.c \
	src_bonus/engine/textures_utils_2_bonus.c \
	src_bonus/engine/doors_bonus.c \
	src_bonus/engine/door_utils_bonus.c \
	src_bonus/engine/minimap_bonus.c \
	src_bonus/engine/minimap_utils_1_bonus.c \
	src_bonus/engine/minimap_utils_2_bonus.c \
	src_bonus/engine/minimap_utils_3_bonus.c \
	src_bonus/parsing/parse_file_bonus.c \
	src_bonus/parsing/parse_file_content_1_bonus.c \
	src_bonus/parsing/parse_file_content_2_bonus.c \
	src_bonus/parsing/parse_file_content_3_bonus.c \
	src_bonus/parsing/parse_map_1_bonus.c \
	src_bonus/parsing/parse_map_2_bonus.c \
	src_bonus/parsing/parse_map_3_bonus.c \
	src_bonus/parsing/parse_rgb_1_bonus.c \
	src_bonus/parsing/parse_rgb_3_bonus.c \
	src_bonus/parsing/parse_textures_1_bonus.c \
	src_bonus/parsing/parse_textures_2_bonus.c \
	src_bonus/parsing/validate_map_1_bonus.c \
	src_bonus/parsing/validate_map_2_bonus.c \
	src_bonus/parsing/validate_map_3_bonus.c \
	src_bonus/parsing/validate_map_4_bonus.c \
	src_bonus/parsing/validate_map_5_bonus.c \
	src_bonus/utils/error_bonus.c \
	src_bonus/utils/utils_1_bonus.c \
	src_bonus/utils/utils_2_bonus.c \
	src_bonus/utils/utils_3_bonus.c \
	src_bonus/utils/utils_4_bonus.c \
	src_bonus/utils/utils_5_bonus.c \
	src_bonus/utils/utils_6_bonus.c \
	src_bonus/utils/utils_7_bonus.c \
	src_bonus/utils/free_bonus.c

OBJS_MANDATORY			= ${SRCS_MANDATORY:.c=.o}
OBJS_BONUS				= ${SRCS_BONUS:.c=.o}

all	:	banner $(NAME)

banner:
	@printf "${BLUE}╔════════════════════════════════════════════════════════════════════════════════════╗${NC}\n"
	@printf "${BLUE}║                                                                                    ║${NC}\n"
	@printf "${RED}║                  ██████╗██╗   ██╗██████╗ ██████╗ ██████╗                           ║${NC}\n"
	@printf "${RED}║                 ██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗                          ║${NC}\n"
	@printf "${RED}║                 ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║                          ║${NC}\n"
	@printf "${RED}║                 ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║                          ║${NC}\n"
	@printf "${RED}║                 ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝                          ║${NC}\n"
	@printf "${RED}║                  ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝                           ║${NC}\n"
	@printf "${BLUE}║                                                                                    ║${NC}\n"
	@printf "${PURPLE}║                        🌟  3D RAYCASTING ENGINE  🌟                                ║${NC}\n"
	@printf "${BLUE}║                                                                                    ║${NC}\n"
	@printf "${CYAN}║    \"Where every pixel tells a story of light and shadow...\"                        ║${NC}\n"
	@printf "${CYAN}║    \"Cast rays through the maze of your imagination...\"                             ║${NC}\n"
	@printf "${CYAN}║    \"Navigate the digital labyrinth with precision...\"                              ║${NC}\n"
	@printf "${BLUE}║                                                                                    ║${NC}\n"
	@printf "${BLUE}╚════════════════════════════════════════════════════════════════════════════════════╝${NC}\n"
	@printf "\n"
	@printf "${YELLOW}📅 Build Date: $(shell date '+%Y-%m-%d %H:%M:%S') UTC${NC}\n"
	@printf "${YELLOW}🏗️   riel-fas ssallami  ${NC}\n"
	@printf "${YELLOW}📋 Project: Cub3D - Raycasting Game Engine${NC}\n"
	@printf "\n"

$(NAME): compile_msg $(OBJS_MANDATORY)
	@printf "${GREEN}🔗 Linking objects to create $(NAME) [MANDATORY]...${NC}\n"
	@$(CC) $(CFLAGS) $(OBJS_MANDATORY) $(LIBS) -o $(NAME)
	@printf "${GREEN}✅ $(NAME) successfully compiled!${NC}\n"
	@printf "${CYAN}🚀 Ready to explore the 3D world!${NC}\n"

bonus: compile_msg_bonus $(BONUS)

$(BONUS): $(OBJS_BONUS)
	@printf "${GREEN}🔗 Linking objects to create $(BONUS) [BONUS]...${NC}\n"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $(BONUS)
	@printf "${GREEN}✅ $(BONUS) successfully compiled with bonus features!${NC}\n"
	@printf "${PURPLE}🎮 Features: Minimap, Doors, Animations, Mouse Rotation!${NC}\n"

src_mandatory/%.o: src_mandatory/%.c $(HEADER_FILES)
	@printf "${GREEN}🔨 Compiling [M] $<...${NC}\n"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

src_bonus/%.o: src_bonus/%.c $(HEADER_FILES_BONUS)
	@printf "${PURPLE}🔨 Compiling [B] $<...${NC}\n"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

compile_msg:
	@printf "${CYAN}🏗️  Compiling MANDATORY source files...${NC}\n"

compile_msg_bonus:
	@printf "${PURPLE}🏗️  Compiling BONUS source files...${NC}\n"

clean:
	@printf "${YELLOW}🧹 Removing object files...${NC}\n"
	@rm -rf $(OBJS_MANDATORY) $(OBJS_BONUS)
	@printf "${YELLOW}✨ Object files cleaned!${NC}\n"

fclean: clean
	@printf "${YELLOW}🗑️  Removing executables...${NC}\n"
	@rm -rf $(NAME) $(BONUS)
	@printf "${YELLOW}🧽 Complete cleanup finished!${NC}\n"

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus banner compile_msg compile_msg_bonus 
