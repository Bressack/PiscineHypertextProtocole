<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oddeven.php                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:04:37 by tarchen           #+#    #+#             */
/*   Updated: 2018/12/07 11:48:19 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

while (1)
{
	echo "Entrez un nombre: ";
	$numb = trim(fgets(STDIN));
	if (feof(STDIN) == 1)
	{
		echo "\n";
		exit();
	}
	if (is_numeric($numb))
	{
		echo "Le chiffre $numb est ";
		if ($numb % 2 != 1)
			echo "Pair\n";
		else
			echo "Impaire\n";
	}
	else
		echo "'$numb' n'est pas un chiffre\n";
}

?>
