// update a property of a node
MATCH (putin: PLAYER)
WHERE ID(putin) = 7
 SET putin.hometown = "Moscow"
RETURN putin

// remove a property of a node
MATCH (putin: PLAYER { number: 37 })
REMOVE putin.height
RETURN putin

// update label of a node
MATCH (putin: PLAYER)
WHERE ID(putin) = 7
REMOVE putin:PLAYER
 SET putin:PRESIDENT
RETURN putin

// update a property of a relationship
MATCH (putin: PLAYER { number: 37 })-[r:PLAYS_FOR]->(team: TEAM)
 SET r.salary = 98000000000
RETURN r
