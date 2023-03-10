/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTnode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:32:38 by nthimoni          #+#    #+#             */
/*   Updated: 2023/03/08 21:53:01 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTNODE_HPP
# define RBTNODE_HPP 

namespace ft
{
	enum class RBTColor : bool
	{
		BLACK = 0,
		RED
	};


	template <typename Type>
	struct RBTNode
	{
		RBTNode(RBTColor color, 
			RBTColor m_color;
			RBTNode* m_left;
			RBTNode* m_right;
			RBTNode* m_parent;
			Type m_value;

	};
}

#endif 
