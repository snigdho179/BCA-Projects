#!/bin/bash

# =========================
#     CONFIGURATION
# =========================
USERNAME="snigdho179"
MOUNT_POINT="/home/$USERNAME/GoogleDrive"
SOURCE_DIR="/home/$USERNAME/Desktop"
REMOTE="gdrive"
DEST_FOLDER="Desktop_Backup"

FINAL_DEST="$MOUNT_POINT/$DEST_FOLDER"


# =========================
#   FUNCTION: Auto-Mount
# =========================
maintain_mount() {
    while true; do
        if ! mountpoint -q "$MOUNT_POINT"; then
            echo "🔌 Google Drive not mounted. Mounting now..."

            rclone mount "$REMOTE": "$MOUNT_POINT" \
                --allow-other \
                --vfs-cache-mode writes \
                --vfs-cache-max-age 5m \
                --dir-cache-time 10s \
                --poll-interval 15s \
                --log-level INFO \
                --daemon

            sleep 5

            if mountpoint -q "$MOUNT_POINT"; then
                echo "✅ Google Drive mounted successfully."
            else
                echo "❌ Failed to mount Google Drive."
            fi
        fi
        sleep 300
    done
}


# =========================
#   START BACKGROUND MOUNTER
# =========================
maintain_mount &
sleep 3


# =========================
#   ENSURE DESTINATION EXISTS
# =========================
if [ ! -d "$FINAL_DEST" ]; then
    echo "📁 Creating destination folder in Google Drive..."
    mkdir -p "$FINAL_DEST"
fi

echo "📌 Watching Desktop for changes..."
echo "Backup will sync to: $FINAL_DEST"
echo "-------------------------------------"


# =========================
#   MAIN WATCH LOOP
# =========================
while inotifywait -r -e modify,create,delete,move "$SOURCE_DIR"; do
    
    if mountpoint -q "$MOUNT_POINT"; then
        echo "🔄 Change detected → Syncing..."

        # 💡 FIXED: rsync freeze problem
        rsync -rtv --whole-file --ignore-times --no-i-r --delete \
            "$SOURCE_DIR/" "$FINAL_DEST/"

        echo "✅ Sync complete."
    else
        echo "⚠️ Google Drive not mounted → Sync skipped."
    fi

    echo "-------------------------------------"
done

