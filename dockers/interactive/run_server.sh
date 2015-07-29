#!/bin/bash
source ./_env.sh
echo "Starting Docker: $TAG"
docker run -i -t $TAG
