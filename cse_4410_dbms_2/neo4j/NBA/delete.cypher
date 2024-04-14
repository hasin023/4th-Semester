// Delete all nodes and relationships
MATCH (n)
DETACH DELETE n

// Delete a specific node
MATCH
(ja { name: "Ja Morant" })
DETACH DELETE ja // detach removes all relationships

// Delete a specific relationship
MATCH
(player:PLAYER { name: "Joel Embiid" }) -[rel:PLAYS_FOR]-> (team:TEAM)
DELETE rel
