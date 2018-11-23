/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:24:56 by tarchen           #+#    #+#             */
/*   Updated: 2018/11/23 16:38:11 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"

# define EXTERN_MARGIN_TOP			5
# define EXTERN_MARGIN_LEFT			200

# define DIV_ATOM_BORDER_WIDTH		1
# define DIV_ATOM_BORDER_STYLE		"solid"
# define DIV_ATOM_WIDTH				75
# define DIV_ATOM_WIDTH_PX			"px"
# define DIV_ATOM_HEIGHT			100
# define DIV_ATOM_HEIGHT_PX			"px"

# define NB_ATOM_FONT_WEIGHT		"bold"
# define NB_ATOM_FONT_SIZE			"12"
# define NB_ATOM_FONT_SIZE_PX		"px"
# define NB_ATOM_PADDING_LEFT		"4"
# define NB_ATOM_PADDING_LEFT_PX	"%"

# define MASS_ATOM_FONT_SIZE		"8"
# define MASS_ATOM_FONT_SIZE_PX		"px"
# define MASS_ATOM_PADDING_LEFT		"13"
# define MASS_ATOM_PADDING_LEFT_PX	"%"

# define SYMBOLE_FONT_SIZE			"40"
# define SYMBOLE_FONT_SIZE_PX		"px"
# define NAME_FONT_SIZE				"8.9"
# define NAME_FONT_SIZE_PX			"px"
# define NAME_FONT_FAMILY			"arial"

# define ATOM_COUNT					118
# define TAB						"0123456789ABCDEF"

# define PATH_FILE					"./mendeleiev.html"

typedef struct		s_atom
{
	int				div_atom_border_width;
	char			*div_atom_border_style;
	int				div_atom_width;
	char			*div_atom_width_px;
	int				div_atom_height;
	char			*div_atom_height_px;
	int				div_atom_margin_top; // dynamic
	int				div_atom_margin_left; // dynamic

	char			*nb_atom_font_weight;
	char			*nb_atom_font_size;
	char			*nb_atom_font_size_px;
	char			*nb_atom_padding_left;
	char			*nb_atom_padding_left_px;
	char			*nb_atom; // dynamic

	char			*mass_atom_font_size;
	char			*mass_atom_font_size_px;
	char			*mass_atom_padding_left;
	char			*mass_atom_padding_left_px;
	char			*mass_atom; // dynamic

	char			*symbole_font_size;
	char			*symbole_font_size_px;
	char			*symbole; // dynamic

	char			*name_font_size;
	char			*name_font_size_px;
	char			*name_font_family;
	char			*name; // dynamic
}					t_atom;

typedef struct		s_data
{
	char			*nb;
	char			*name;
	char			*symbole;
	char			*mass;
	int				row;
	int				col;
}					t_data;

t_data	data[ATOM_COUNT + 1][6] =
{
	{"1",	"Hydrogène",		"H",	"1,00794",		1,	1},
	{"2",	"Hélium",			"He",	"4,00260",		1,	18},
	{"3",	"Lithium",	 		"Li",	"6,94100",		2,	1},
	{"4",	"Béryllium",		"Be",	"9,01218",		2,	2},
	{"5",	"Bore",				"B",	"10,81100",		2,	13},
	{"6",	"Carbone",			"C",	"12,01100",		2,	14},
	{"7",	"Azote",			"N",	"14,00674",		2,	15},
	{"8",	"Oxygène",			"O",	"15,99940",		2,	16},
	{"9",	"Fluor",			"F",	"18,99840",		2,	17},
	{"10",	"Néon",				"Ne",	"20,17970",		2,	18},
	{"11",	"Sodium",			"Na",	"22,98976",		3,	1},
	{"12",	"Magnésium",		"Mg",	"24,30500",		3,	2},
	{"13",	"Aluminium",		"Al",	"26,98153",		3,	13},
	{"14",	"Silicium",			"Si",	"28,08550",		3,	14},
	{"15",	"Phosphore",		"P",	"30,97376",		3,	15},
	{"16",	"Soufre",			"S",	"32,06600",		3,	16},
	{"17",	"Chlore",			"Cl",	"35,45270",		3,	17},
	{"18",	"Argon",			"Ar",	"39,94800",		3,	18},
	{"19",	"Potassium",		"K",	"39,09830",		4,	1},
	{"20",	"Calcium",			"Ca",	"40,07800",		4,	2},
	{"21",	"Scandium",			"Sc",	"44,95591",		4,	3},
	{"22",	"Titane",			"Ti",	"47,88000",		4,	4},
	{"23",	"Vanadium",			"V",	"50,94150",		4,	5},
	{"24",	"Chrome",			"Cr",	"51,99610",		4,	6},
	{"25",	"Manganèse",		"Mn",	"54,93805",		4,	7},
	{"26",	"Fer",				"Fe",	"55,84700",		4,	8},
	{"27",	"Cobalt",			"Co",	"58,93320",		4,	9},
	{"28",	"Nickel",			"Ni",	"58,69000",		4,	10},
	{"29",	"Cuivre",			"Cu",	"63,54600",		4,	11},
	{"30",	"Zinc",			 	"Zn",	"65,39000",		4,	12},
	{"31",	"Gallium",			"Ga",	"69,72300",		4,	13},
	{"32",	"Germanium",		"Ge",	"72,61000",		4,	14},
	{"33",	"Arsenic",			"As",	"74,92159",		4,	15},
	{"34",	"Sélénium",			"Se",	"78,96000",		4,	16},
	{"35",	"Brome",			"Br",	"79,90400",		4,	17},
	{"36",	"Krypton",			"Kr",	"83,80000",		4,	18},
	{"37",	"Rubidium",			"Rb",	"85,46780",		5,	1},
	{"38",	"Strontium",		"Sr",	"87,62000",		5,	2},
	{"39",	"Yttrium",			"Y",	"88,90585",		5,	3},
	{"40",	"Zirconium",		"Zr",	"91,22400",		5,	4},
	{"41",	"Niobium",			"Nb",	"92,90638",		5,	5},
	{"42",	"Molybdène",		"Mo",	"95,94000",		5,	6},
	{"43",	"Technétium",		"Tc",	"98,90630",		5,	7},
	{"44",	"Ruthénium",		"Ru",	"101,07000",	5,	8},
	{"45",	"Rhodium",			"Rh",	"102,90550",	5,	9},
	{"46",	"Palladium",		"Pd",	"106,42000",	5,	10},
	{"47",	"Argent",			"Ag",	"107,86820",	5,	11},
	{"48",	"Cadmium",			"Cd",	"112,41100",	5,	12},
	{"49",	"Indium",			"In",	"114,82000",	5,	13},
	{"50",	"Étain",			"Sn",	"118,71000",	5,	14},
	{"51",	"Antimoine",		"Sb",	"121,75000",	5,	15},
	{"52",	"Tellure",			"Te",	"127,60000",	5,	16},
	{"53",	"Iode",			 	"I",	"126,90447",	5,	17},
	{"54",	"Xénon",			"Xe",	"131,29000",	5,	18},
	{"55",	"Césium",			"Cs",	"132,90543",	6,	1},
	{"56",	"Baryum",			"Ba",	"137,32700",	6,	2},
	{"57",	"Lanthane",			"La",	"138,90550",	9,	4},
	{"58",	"Cérium",			"Ce",	"140,11500",	9,	5},
	{"59",	"Praséodyme",		"Pr",	"140,90765",	9,	6},
	{"60",	"Néodyme",			"Nd",	"144,24000",	9,	7},
	{"61",	"Prométhium",		"Pm",	"146,91510",	9,	8},
	{"62",	"Samarium",			"Sm",	"150,36000",	9,	9},
	{"63",	"Europium",			"Eu",	"151,96500",	9,	10},
	{"64",	"Gadolinium",		"Gd",	"157,25000",	9,	11},
	{"65",	"Terbium",			"Tb",	"158,92534",	9,	12},
	{"66",	"Dysprosium",		"Dy",	"162,50000",	9,	13},
	{"67",	"Holmium",			"Ho",	"164,93032",	9,	14},
	{"68",	"Erbium",			"Er",	"167,26000",	9,	15},
	{"69",	"Thulium",			"Tm",	"168,93421",	9,	16},
	{"70",	"Ytterbium",		"Yb",	"173,04000",	9,	17},
	{"71",	"Lutécium",			"Lu",	"174,96700",	9,	18},
	{"72",	"Hafnium",			"Hf",	"178,49000",	6,	4},
	{"73",	"Tantale",			"Ta",	"180,94790",	6,	5},
	{"74",	"Tungstène",		"W",	"183,85000",	6,	6},
	{"75",	"Rhénium",			"Re",	"186,20700",	6,	7},
	{"76",	"Osmium",			"Os",	"190,20000",	6,	8},
	{"77",	"Iridium",			"Ir",	"192,22000",	6,	9},
	{"78",	"Platine",			"Pt",	"195,08000",	6,	10},
	{"79",	"Or",				"Au",	"196,96650",	6,	11},
	{"80",	"Mercure",			"Hg",	"200,59000",	6,	12},
	{"81",	"Thallium",			"Tl",	"204,38330",	6,	13},
	{"82",	"Plomb",			"Pb",	"207,20000",	6,	14},
	{"83",	"Bismuth",			"Bi",	"208,98030",	6,	15},
	{"84",	"Polonium",			"Po",	"208,98240",	6,	16},
	{"85",	"Astate",			"At",	"209,98710",	6,	17},
	{"86",	"Radon",			"Rn",	"222,01760",	6,	18},
	{"87",	"Francium",			"Fr",	"223,01970",	7,	1},
	{"88",	"Radium",			"Ra",	"226,02540",	7,	2},
	{"89",	"Actinium",			"Ac",	"227,02780",	10,	4},
	{"90",	"Thorium",			"Th",	"232,03810",	10,	5},
	{"91",	"Protactinium",		"Pa",	"231,03590",	10,	6},
	{"92",	"Uranium",			"U",	"238,02890",	10,	7},
	{"93",	"Neptunium",		"Np",	"237,04820",	10,	8},
	{"94",	"Plutonium",		"Pu",	"244,06420",	10,	9},
	{"95",	"Américium",		"Am",	"243,06140",	10,	10},
	{"96",	"Curium",			"Cm",	"247,07030",	10,	11},
	{"97",	"Berkélium",		"Bk",	"247,07030",	10,	12},
	{"98",	"Californium",		"Cf",	"251,07960",	10,	13},
	{"99",	"Einsteinium",		"Es",	"252,08290",	10,	14},
	{"100",	"Fermium",			"Fm",	"257,09510",	10,	15},
	{"101",	"Mendélévium",		"Md",	"258,09860",	10,	16},
	{"102",	"Nobélium",			"No",	"259,10090",	10,	17},
	{"103",	"Lawrencium",		"Lr",	"260,10530",	10,	18},
	{"104",	"Rutherfordium",	"Rf",	"261,10870",	7,	4},
	{"105",	"Dubnium",			"Db",	"262,11380",	7,	5},
	{"106",	"Seaborgium",		"Sg",	"263,11820",	7,	6},
	{"107",	"Bohrium",			"Bh",	"262,12290",	7,	7},
	{"108",	"Hassium",			"Hs",	"265,00000",	7,	8},
	{"109",	"Meitnérium",		"Mt",	"266,00000",	7,	9},
	{"110",	"Darmstadtium",		"Ds",	"269,00000",	7,	10},
	{"111",	"Roentgenium",		"Rg",	"272,00000",	7,	11},
	{"112",	"Copernicium",		"Cn",	"277,00000",	7,	12},
	{"113",	"Nihonium",			"Nh",	"286,00000",	7,	13},
	{"114",	"Flérovium",		"Fl",	"000,00000",	7,	14},
	{"115",	"Moscovium",		"Mc",	"000,00000",	7,	15},
	{"116",	"Livermorium",		"Lv",	"000,00000",	7,	16},
	{"117",	"Tennesse",			"Ts",	"000,00000",	7,	17},
	{"118",	"Oganesson",		"Og",	"000,00000",	7,	18},
	{0,		0,					0,		0,				0,	0}
};

void	next_atom_init(t_atom *atom, int i)
{
	atom->div_atom_margin_top		= (DIV_ATOM_HEIGHT + 5) * (data[i]->row - 1) + EXTERN_MARGIN_TOP;
	atom->div_atom_margin_left		= (DIV_ATOM_WIDTH + 5) * (data[i]->col - 1) + EXTERN_MARGIN_LEFT;
	atom->nb_atom					= data[i]->nb;
	atom->mass_atom					= data[i]->mass;
	atom->symbole					= data[i]->symbole;
	atom->name						= data[i]->name;
}

void	init(t_atom *atom)
{
	atom->div_atom_border_width		= DIV_ATOM_BORDER_WIDTH;
	atom->div_atom_border_style		= DIV_ATOM_BORDER_STYLE;
	atom->div_atom_width			= DIV_ATOM_WIDTH;
	atom->div_atom_width_px			= DIV_ATOM_WIDTH_PX;
	atom->div_atom_height			= DIV_ATOM_HEIGHT;
	atom->div_atom_height_px		= DIV_ATOM_HEIGHT_PX;
	atom->div_atom_margin_top		= 0;
	atom->div_atom_margin_left		= 0;
	atom->nb_atom_font_weight		= NB_ATOM_FONT_WEIGHT;
	atom->nb_atom_font_size			= NB_ATOM_FONT_SIZE;
	atom->nb_atom_font_size_px		= NB_ATOM_FONT_SIZE_PX;
	atom->nb_atom_padding_left		= NB_ATOM_PADDING_LEFT;
	atom->nb_atom_padding_left_px	= NB_ATOM_PADDING_LEFT_PX;
	atom->nb_atom					= 0;
	atom->mass_atom_font_size		= MASS_ATOM_FONT_SIZE;
	atom->mass_atom_font_size_px	= MASS_ATOM_FONT_SIZE_PX;
	atom->mass_atom_padding_left	= MASS_ATOM_PADDING_LEFT;
	atom->mass_atom_padding_left_px	= MASS_ATOM_PADDING_LEFT_PX;
	atom->mass_atom					= 0;
	atom->symbole_font_size			= SYMBOLE_FONT_SIZE;
	atom->symbole_font_size_px		= SYMBOLE_FONT_SIZE_PX;
	atom->symbole					= 0;
	atom->name_font_size			= NAME_FONT_SIZE;
	atom->name_font_size_px			= NAME_FONT_SIZE_PX;
	atom->name_font_family			= NAME_FONT_FAMILY;
	atom->name						= 0;
}

int		main(void)
{
	t_atom	atom;
	int		fd;

	srand(time(NULL));
	if ((fd = open(PATH_FILE, O_WRONLY)) == -1)
		return (1);
	init(&atom);
	dprintf(fd,
"<!DOCTYPE html>\n\
<html lang=\"fr\">\n\
\t<head>\n\
\t\t<meta charset=\"utf-8\">\n\
\t\t<title>Tableau de Mendeleïev</title>\n\
\t</head>\n\
\t<body>\n\
\t\t<div class=\"title\">\n\
\t\t\t<h1 style=\"font-size: 50px; text-align: center; font-family: arial;\">\n\
\t\t\t\tTABLEAU PÉRIODIQUE DES ÉLÉMENTS</h1>\n\
\t\t</div>\n\
\t<img style=\"position:absolute; margin-left: 360px; margin-top: -4px;\" src=\"https://www.herodote.net/Images/mendeleievmaxi.jpg\" alt=\"mendeleiev photo\">\n");
	for (size_t i = 0; i < ATOM_COUNT; i++)
	{
		next_atom_init(&atom, i);
		printf("new node [ %03s ]: %s\n", atom.nb_atom, atom.name);
		dprintf(fd,
"\t<div class=\"ATOM\" style=\"background-color:#%c%c%c%c%c%c; border-style:%s; border-width: %dpx; width:%d%s; height:%d%s; position:absolute; margin: %d%s 0 0 %d%s;\">\n\
\t\t<div class=\"NB_MASS\" style=\"\">\n\
\t\t\t<h style=\"font-weight:%s; font-size: %s%s; padding-left: %s%s;\">\n\
\t\t\t\t%s</h>\n\
\t\t\t<h style=\"font-size: %s%s; padding-left: %s%s;\">\n\
\t\t\t\t%s</h></div>\n\
\t\t<div class=\"SYMBOLE\" style=\"font-size: %s%s; text-align: center;\">\n\
\t\t\t%s</div>\n\
\t\t<div class=\"NAME\" style=\"font-size: %s%s; text-align: center; font-family: %s;\">\n\
\t\t\t%s</div>\n\
\t</div>\n",

							TAB[ft_rand_btw(7,15)],
							TAB[ft_rand_btw(7,15)],
							TAB[ft_rand_btw(7,15)],
							TAB[ft_rand_btw(7,15)],
							TAB[ft_rand_btw(7,15)],
							TAB[ft_rand_btw(7,15)],
		/*	char	*/		atom.div_atom_border_style,
		/*	int		*/		atom.div_atom_border_width,
		/*	int		*/		atom.div_atom_width,
		/*	char	*/		atom.div_atom_width_px,
		/*	int		*/		atom.div_atom_height,
		/*	char	*/		atom.div_atom_height_px,
		/*	int		*/		atom.div_atom_margin_top,
							atom.div_atom_margin_top > 0 ? "px" : "",
		/*	int		*/		atom.div_atom_margin_left,
							atom.div_atom_margin_left > 0 ? "px" : "",
		/*	char	*/		atom.nb_atom_font_weight,
		/*	char	*/		atom.nb_atom_font_size,
		/*	char	*/		atom.nb_atom_font_size_px,
		/*	char	*/		atom.nb_atom_padding_left,
		/*	char	*/		atom.nb_atom_padding_left_px,
		/*	char	*/		atom.nb_atom,
		/*	char	*/		atom.mass_atom_font_size,
		/*	char	*/		atom.mass_atom_font_size_px,
		/*	char	*/		atom.mass_atom_padding_left,
		/*	char	*/		atom.mass_atom_padding_left_px,
		/*	char	*/		atom.mass_atom,
		/*	char	*/		atom.symbole_font_size,
		/*	char	*/		atom.symbole_font_size_px,
		/*	char	*/		atom.symbole,
		/*	char	*/		atom.name_font_size,
		/*	char	*/		atom.name_font_size_px,
		/*	char	*/		atom.name_font_family,
		/*	char	*/		atom.name
		);
	}
	dprintf(fd,
"\t</body>\n\
</html>\n");
	return (0);
}
