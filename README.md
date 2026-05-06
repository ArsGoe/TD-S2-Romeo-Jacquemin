## Exo 2.1

WeightedGraph - constitué d'une liste d'adjacence (les arêtes entre deux noeuds). Pour chaque point, on donne les arêtes qui partent de lui (les arêtes contenant l'information du point d'arrivée et du poids).

PositionedGraph - Le positionedGraph est un WeightedGraph avec une information en plus, des coordonnées (x,y) pour les placer.

## Exo 2.2

Extraction OSM - Extraction et traduction les données du fichier osm pour les préparer à l'affichage dans un graph

Simplification - modifie les données pour supprimer les redondances et informations non utiles.

Visualisation - Récupère le ficher graph et affiche les points.

## Exo 2.3

keep_only_largest_connected_component garde les sous-graphes avec le plus de points (en vrai j'ai rien compris)
on retire les petits graphes pas utiles

remove_small_ending_edge - si un point est la fin d'un trait et qu'il est très proche de lui, on les fusionnent.
ça évite d'avoir des points inutiles mais si beaucoup de points font ça, on perd beaucoup d'informations

remove_degree_two_nodes_by_angle_threshold  - si les angles sont trop proches d'une ligne droite, on retire le point et on relie les autres
perte d'info mais ça évite des noeuds inutiles.

group_nodes_by_connection_depth_and_proximity - aucune idée
aucune idée encore